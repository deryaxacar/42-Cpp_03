<div align="center">
  <h1>C++ Module 03</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>

</div>
<p align="center" >
    Bu proje, nesne yönelimli programlama (OOP) prensiplerini kullanarak temel bir oyun karakteri simülasyonu gerçekleştirmektedir. 
  `ClapTrap`, `ScavTrap` ve `FragTrap` sınıfları, karakterlerin özelliklerini ve yeteneklerini modellemek amacıyla 
  miras alma (inheritance) özelliğinden faydalanmaktadır. Her bir sınıf, kendine özgü özellikler ve metotlar içerirken, 
  üst sınıfın (ClapTrap) temel işlevselliğinden yararlanmaktadır. 
  </p>


### İçindekiler 📚
- [Ex00 - Aaaaand... OPEN!](#ex00---aaaaand-open)
- [Ex01 - Serena, my love!](#ex01---serena-my-love)
- [Ex02 - Repetitive work](#ex02---repetitive-work)
- [Miras Alma (inheritance) Nedir?](#miras-alma-inheritance-nedir)

---

<a name="ex00---aaaaand-open"></a>
## Ex00 - Aaaaand... OPEN!

**Gereksinimler**
1. **ClapTrap Sınıfı**:
   - **Özel Değişkenler**:
     - `Name` (parametre olarak alınacak)
     - `Hit points` (10)
     - `Energy points` (10)
     - `Attack damage` (0)
    - **kod**
    - ```cpp
      private:
            std::string name;
            int hitPoint;
            int energyPoint;
            int attackDamage;
      ```
      
    - Constructor ile başlangıç değerlerinin ayarlanması:
    - ```cpp
      ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10),attackDamage(0)
      {
        std::cout << this->getName() <<": Constructor call" << std::endl;
      }
        ```

2. **Public Üye Fonksiyonları**:
   - `void attack(const std::string& target);`
     - Hedefe saldırı yapar, hasar verir. Enerji puanı 1 azalır.
     - ```cpp
        void ClapTrap::attack(const std::string& target)
        {
            // Eğer ClapTrap'in hitPoint veya energyPoint'i 0 veya daha düşükse
            if(this->hitPoint <= 0 || this->energyPoint <= 0)
            {
                std::cout << "I cannot do anything" << std::endl; // Yapamayacağını belirt
                return; // Fonksiyondan çık
            }
            
            // Enerji puanı varsa saldırı yap
            if(this->energyPoint > 0)
            {
                std::cout << this->name << " attacks " << target << " causing " << this->attackDamage << " damage!\n"; 
                this->energyPoint -= 1; // Enerji puanını azalt
            }
        }
         ```
   - `void takeDamage(unsigned int amount);`
     - Belirtilen miktarda hasar alır.
     - ```cpp
        void ClapTrap::takeDamage(unsigned int amount)
        {
            // Mevcut hit point'leri göster
            std::cout << this->name << " Hit points: " << this->hitPoint << " points\n";
            
            // Eğer hit point'ler 0 veya daha düşükse, fonksiyondan çık
            if(this->hitPoint <= 0)
                return;
            
            // Eğer hasar miktarı 0'dan büyükse
            if(int(amount) > 0)
            {
                std::cout << this->name << " has taken " << (int)amount << " damage!" << std::endl; // Hasar mesajı yazdır
                this->hitPoint -= (int)amount; // Hit point'leri azalt
            }
        
            // Eğer hit point'ler 0 veya daha düşükse, ölüm mesajı yazdır
            if(this->hitPoint <= 0)
            {
                std::cout << this->name << " dies..\n";
            }
        }
        ```
   - `void beRepaired(unsigned int amount);`
     - Belirtilen miktarda can yeniler. Enerji puanı 1 azalır.
     - ```cpp
        void ClapTrap::beRepaired(unsigned int amount)
        {
            // Mevcut hit point'leri göster
            std::cout << this->name << " Hit points: " << this->hitPoint << " points\n";
            
            // Eğer hit point'ler veya enerji puanları 0 veya daha düşükse, fonksiyondan çık
            if(this->hitPoint <= 0 || this->energyPoint <= 0)
            {
                std::cout << "I cannot do anything" << std::endl; // Yapamayacağını belirt
                return;
            }
            
            // Eğer enerji puanı varsa ve onarıma uygun bir miktar belirtilmişse
            if(this->energyPoint > 0 && (int)amount >= 0)
            {
                std::cout << this->name << " healed " << amount << " points\n"; // Onarım mesajı yazdır
                this->hitPoint += (int)amount; // Hit point'leri artır
                this->energyPoint -= 1; // Enerji puanını azalt
            }
        
            // Yeni hit point'leri göster
            std::cout << this->name << " New Hit points: " << this->hitPoint << " points\n";
        }
        ```

3. **Mesajlar**:
   - Her fonksiyon çağrıldığında, durumu belirten bir mesaj yazdırmalıdır.
   - Yapıcı ve yıkıcı fonksiyonlar için de mesaj gösterilmelidir.
---

<a name="ex01---serena-my-love"></a>
## Ex01 - Serena, my love!

**Gereksinimler**
1. **ScavTrap Sınıfı**:
   - **ClapTrap Sınıfından Türetilecektir**:
     - Yapıcı ve yıkıcı fonksiyonları ClapTrap'tan miras alacak.
     - **kod**
     - ```cpp
        ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
        {
            // Hit points, energy points ve attack damage değerlerini ayarla
            this->setVar(name, 100, 50, 20);
            
            // ScavTrap yapıcısının çağrıldığını belirt
            std::cout << this->getName() << ": ScavTrap Constructor call\n";
        }
       ```
       - Not : `ScavTrap` sınıfı `ClapTrap` sınıfından miras aldığı için, kendi değerlerini `setVar(name, 100, 50, 20);` gibi bir fonksiyon kullanarak atar
   - Saldırı (`attack()`) fonksiyonu farklı bir mesaj yazdıracak.
     - ```cpp
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
       ```

2. **Yeni Üye Fonksiyonu**:
   - `void guardGate();`
     - Bu fonksiyon, ScavTrap'ın Gate Keeper moduna geçtiğini belirten bir mesaj yazdıracak.
     - ```cpp
        void ScavTrap::guardGate()
        {
            std::cout << getName() << " ScavTrap is now in Gatekeeper mode.\n";
        }
       ```

3. **Yapıcı ve Yıkıcı İşlemleri**:
   - `ScavTrap` oluşturulurken, önce `ClapTrap` oluşturulmalıdır. Tersine yok etme sırası korunmalıdır.

---

<a name="ex02---repetitive-work"></a>
## Ex02 - Repetitive work

**Gereksinimler**
1. **FragTrap Sınıfı**:
   - **ClapTrap Sınıfından Türetilecektir**:
     - Kendi yapıcı ve yıkıcı fonksiyonları olacak. Yapıcı, `ClapTrap`'ın yapıcısını çağıracak ve farklı bir mesaj yazdıracak.
     - ```cpp
        FragTrap::FragTrap(std::string name) : ClapTrap(name)
        {
            this->setVar(name,100,100,30);
            std::cout << this->getName() << ": FragTrap Constructor call\n";
        }
        ```

2. **Değişkenler**:
   - `Name` (parametre olarak alınacak)
   - `Hit points` (100)
   - `Energy points` (100)
   - `Attack damage` (30)
   - ```cpp
        FragTrap::FragTrap(std::string name) : ClapTrap(name)
        {
            this->setVar(name,100,100,30);
            std::cout << this->getName() << ": FragTrap Constructor call\n";
        }
        ```

3. **Yeni Üye Fonksiyonu**:
   - `void highFivesGuys(void);`
     - Bu fonksiyon, pozitif bir "high five" isteği yazdıracak.
     - ```cpp
        void FragTrap::highFivesGuys(void)
        {
            // Eğer hit point'ler 0 veya daha düşükse, fonksiyondan çık
            if(this->getHitPoint() <= 0)
                return;
        
            // FragTrap'ın high five isteğini yazdır
            std::cout << this->getName() << ": GIVE ME A FIVER, MAN!\n";
        }
        ```

4. **Yapıcı ve Yıkıcı İşlemleri**:
   - `FragTrap` oluşturulurken, önce `ClapTrap` oluşturulmalı ve ardından `FragTrap` yapıcısı kendi değerlerini ayarlamalıdır. Tersine yok etme sırası korunmalıdır.

---

<a name="miras-alma-inheritance-nedir"></a>
## Miras Alma (inheritance) Nedir?

Miras alma (inheritance), nesne yönelimli programlamada (OOP) kullanılan bir kavramdır. Bir sınıfın (üst sınıf) özelliklerinin (değişkenler ve metotlar) başka bir sınıf (alt sınıf) tarafından devralınması anlamına gelir. Bu, kodun yeniden kullanılabilirliğini artırır ve daha temiz, düzenli bir yapı sağlar.

### Temel Kavramlar

- **Üst Sınıf (Base Class)**: Diğer sınıflar tarafından kullanılabilecek genel özellikler ve metotlar içerir. Örneğin, `ClapTrap` sınıfı.

- **Alt Sınıf (Derived Class)**: Üst sınıftan miras alan sınıf. Üst sınıfın özelliklerini devralır ve kendi özel özelliklerini ekleyebilir. Örneğin, `ScavTrap` ve `FragTrap`.

### Miras Alma Türleri

- **Tek Miras**: Bir alt sınıf yalnızca bir üst sınıftan miras alır.
- **Çoklu Miras**: Bir alt sınıf birden fazla üst sınıftan miras alabilir.
- **Hiyerarşik Miras**: Bir üst sınıf birden fazla alt sınıfa sahiptir.

### Neden Kullanılır?

- **Kod Yeniden Kullanımı**: Ortak özellikler ve metotlar bir üst sınıfta tanımlanarak alt sınıflarda tekrar yazılmasına gerek kalmaz.
- **Daha İyi Organizasyon**: İlgili sınıflar arasında hiyerarşi oluşturarak kodun düzenli ve okunabilir olmasını sağlar.
- **Polimorfizm**: Alt sınıfların, üst sınıfın metotlarını özelleştirerek farklı davranışlar sergilemesine olanak tanır.

**Örnek**
```cpp
    class ClapTrap {
    public:
        void attack();
    };
    
    class ScavTrap : public ClapTrap {
    public:
        void guardGate();
    };
  ```

Yukarıdaki örnekte ScavTrap, ClapTrap sınıfından miras alır ve attack() metodunu devralır, ayrıca kendi özel metodunu tanımlar.

---

<p align="center">2025 This project was created by Derya ACAR.</p>

