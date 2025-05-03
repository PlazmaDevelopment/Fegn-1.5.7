#ifndef FEGN_CACHE_HPP
#define FEGN_CACHE_HPP

#include <string>
#include <memory>
#include <map>
#include <chrono>

namespace Fegn {
    // Cache öğesi
    class CacheItem {
    public:
        std::string value;
        std::chrono::steady_clock::time_point expiresAt;
        
        CacheItem(const std::string& value, std::chrono::steady_clock::time_point expiresAt)
            : value(value), expiresAt(expiresAt) {}
        
        bool isExpired() const {
            return std::chrono::steady_clock::now() > expiresAt;
        }
    };
    
    // Cache yöneticisi
    class CacheManager {
    private:
        std::map<std::string, std::shared_ptr<CacheItem>> items;
        
    public:
        // Öğe ekleme
        void set(const std::string& key, const std::string& value, std::chrono::seconds duration) {
            auto expiresAt = std::chrono::steady_clock::now() + duration;
            items[key] = std::make_shared<CacheItem>(value, expiresAt);
        }
        
        // Öğe alma
        std::string get(const std::string& key) {
            if (items.find(key) != items.end()) {
                auto item = items[key];
                if (!item->isExpired()) {
                    return item->value;
                }
                items.erase(key);
            }
            return "";
        }
        
        // Öğe silme
        void remove(const std::string& key) {
            items.erase(key);
        }
        
        // Tüm önbelleği temizle
        void clear() {
            items.clear();
        }
    };
    
    // Cache istemcisi
    class CacheClient {
    private:
        std::shared_ptr<CacheManager> manager;
        
    public:
        CacheClient(std::shared_ptr<CacheManager> manager)
            : manager(manager) {}
        
        void set(const std::string& key, const std::string& value, std::chrono::seconds duration) {
            manager->set(key, value, duration);
        }
        
        std::string get(const std::string& key) {
            return manager->get(key);
        }
        
        void remove(const std::string& key) {
            manager->remove(key);
        }
        
        void clear() {
            manager->clear();
        }
    };
}

#endif // FEGN_CACHE_HPP
