#ifndef FEGN_VALIDATOR_HPP
#define FEGN_VALIDATOR_HPP

#include <string>
#include <memory>
#include <map>
#include <vector>

namespace Fegn {
    // Doğrulama hatası
    class ValidationError {
    public:
        std::string field;
        std::string message;
        
        ValidationError(const std::string& field, const std::string& message)
            : field(field), message(message) {}
    };
    
    // Doğrulama yöneticisi
    class Validator {
    private:
        std::vector<std::shared_ptr<ValidationError>> errors;
        
    public:
        // Temel doğrulama
        bool validate(const std::string& value, const std::string& type) {
            switch (type) {
                case "email":
                    return isValidEmail(value);
                case "number":
                    return isValidNumber(value);
                case "string":
                    return isValidString(value);
                default:
                    return true;
            }
        }
        
        // Özel doğrulama
        bool validateUser(const std::map<std::string, std::string>& user) {
            bool isValid = true;
            
            if (!validate(user["email"], "email")) {
                errors.push_back(std::make_shared<ValidationError>("email", "Geçersiz e-posta adresi"));
                isValid = false;
            }
            
            if (!validate(user["age"], "number")) {
                errors.push_back(std::make_shared<ValidationError>("age", "Geçersiz yaş değeri"));
                isValid = false;
            }
            
            return isValid;
        }
        
        // Hata alımı
        std::vector<std::shared_ptr<ValidationError>> getErrors() {
            return errors;
        }
        
    private:
        bool isValidEmail(const std::string& email) {
            // E-posta doğrulama
            return true;
        }
        
        bool isValidNumber(const std::string& number) {
            // Sayı doğrulama
            return true;
        }
        
        bool isValidString(const std::string& str) {
            // String doğrulama
            return true;
        }
    };
    
    // Doğrulama istemcisi
    class ValidatorClient {
    private:
        std::shared_ptr<Validator> validator;
        
    public:
        ValidatorClient(std::shared_ptr<Validator> validator)
            : validator(validator) {}
        
        bool validate(const std::string& value, const std::string& type) {
            return validator->validate(value, type);
        }
        
        bool validateUser(const std::map<std::string, std::string>& user) {
            return validator->validateUser(user);
        }
        
        std::vector<std::shared_ptr<ValidationError>> getErrors() {
            return validator->getErrors();
        }
    };
}

#endif // FEGN_VALIDATOR_HPP
