# Fegn 1.5.7

Fegn, Wholf dilinde entegrasyon ve veri yönetimi için kullanılan gelişmiş bir kütüphanedir.

## Yeni Özellikler

- WebSocket desteği
- Cache yönetimi
- Veri doğrulama
- Gelişmiş hata yönetimi
- Stream desteği
- Event sourcing

## Kurulum

```wholf
fort import "Fegn-1.5.7"
```

## Kullanım Örnekleri

### WebSocket

```wholf
// WebSocket bağlantısı
fegn WebSocket {
    connect: "wss://ws.example.com",
    onMessage: (message) => {
        Console.log("Mesaj alındı: " + message)
    },
    onError: (error) => {
        Console.log("Hata: " + error)
    }
}
```

### Cache

```wholf
// Cache yönetimi
fegn Cache {
    set: (key, value, duration) => {
        // Cache'e değer ekle
    },
    get: (key) => {
        // Cache'den değer al
    },
    remove: (key) => {
        // Cache'den değer sil
    }
}
```

### Veri Doğrulama

```wholf
// Veri doğrulama
fegn Validator {
    validate: (data, schema) => {
        // Veri doğrulama
    },
    validateUser: (user) => {
        // Kullanıcı doğrulama
    }
}
```

### Hata Yönetimi

```wholf
// Hata yönetimi
fegn ErrorManager {
    handleError: (error) => {
        // Hata yönetimi
    },
    logError: (error) => {
        // Hata kaydı
    }
}
```

## Lisans

MIT License
