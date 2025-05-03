#ifndef FEGN_ERROR_MANAGER_HPP
#define FEGN_ERROR_MANAGER_HPP

#include <string>
#include <memory>
#include <map>
#include <vector>

namespace Fegn {
    // Hata bilgisi
    class ErrorInfo {
    public:
        std::string message;
        std::string type;
        std::string stack;
        
        ErrorInfo(const std::string& message, const std::string& type, const std::string& stack)
            : message(message), type(type), stack(stack) {}
    };
    
    // Hata yöneticisi
    class ErrorManager {
    private:
        std::vector<std::shared_ptr<ErrorInfo>> errors;
        
    public:
        // Hata yönetimi
        void handleError(const std::string& message, const std::string& type = "error") {
            auto error = std::make_shared<ErrorInfo>(message, type, getStackTrace());
            errors.push_back(error);
            logError(error);
        }
        
        // Hata kaydı
        void logError(const std::shared_ptr<ErrorInfo>& error) {
            // Hata kaydı
        }
        
        // Hata alımı
        std::vector<std::shared_ptr<ErrorInfo>> getErrors() {
            return errors;
        }
        
    private:
        std::string getStackTrace() {
            // Stack trace al
            return "";
        }
    };
    
    // Hata istemcisi
    class ErrorClient {
    private:
        std::shared_ptr<ErrorManager> manager;
        
    public:
        ErrorClient(std::shared_ptr<ErrorManager> manager)
            : manager(manager) {}
        
        void handleError(const std::string& message, const std::string& type = "error") {
            manager->handleError(message, type);
        }
        
        std::vector<std::shared_ptr<ErrorInfo>> getErrors() {
            return manager->getErrors();
        }
    };
}

#endif // FEGN_ERROR_MANAGER_HPP
