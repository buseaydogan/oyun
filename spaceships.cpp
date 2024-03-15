
#include <iostream>
#include "spaceships.h"

//çözülecek sorunlar:
//destructorlar yapılacak()
//single responsibility bakılabilir
//declaration ve definitionları ayırcaz
//gecersiz gemi seciminde secim fonksiyonunu tekrar cağır

    //UPDATES
    int Spaceships::GetDemage(int demage_) {
        health -= demage_*damageCoef;
        int health_after_demage = (health > 0) ? health : 0;
        return health;
    }

    void Spaceships::earnMoney(int prize_) {
        money += prize_;
    }

    void Spaceships::loseMoney(void) {
        int moneyLoss = (rand() % 3 + 1);
        moneyLoss = moneyLoss * 10;
        }

    void Spaceships::updateFuel(void) {
        fuel -= spentFuel;
    }

    void Spaceships::asteroid(void) {
        int asteroidDamage = (rand() % 4) == 0&1&2 ? 10: 0;
        std::cout<<"\nAsteroid kuşağından geçiyorsun!\n\n";
        std::cout<<"                      .:'\n"
                   "         ....     _.::'\n"
                   "       .:-\"\"-:.  (_.'\n"
                   "     .:/      \\:.\n"
                   "     :|        |:\n"
                   "     ':\\      /:'\n"
                   "      '::-..-::'\n"
                   "        `''''`";
        if(asteroidDamage>0) {
            GetDemage(5);
            std::cout<<"\nAsteroidlerden birine çarpıp "<<asteroidDamage<<" hasar aldın.\n\n";
        }
        else {
            std::cout<<"\nAsteroid kuşağından hasar almadan geçtin. Yakıtın azaldı.\n";
            updateFuel();
        }
    }

    void Spaceships::abandonedPlanet(void) {
        int oran = (rand() % 2) == 0 ? 10 : 0;
        if (oran > 0) {
            std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                         "⠀⠀⠀⠀⠀⠀⢯⠙⠩⠀⡇⠊⠽⢖⠆⠀⠀⠀⠀⠀\n"
                         "⠀⠀⠀⠀⠀⠀⠀⠱⣠⠀⢁⣄⠔⠁⠀⠀⠀⠀⠀⠀\n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⣷⣶⣾⣾⠀⠀⠀⠀⠀⠀⠀⠀\n"
                         "⠀⠀⠀⠀⠀⠀⢀⡔⠙⠈⢱⡟⣧⠀⠀⠀⠀⠀⠀⠀\n"
                         "⠀⠀⠀⠀⠀⡠⠊⠀⠀⣀⡀⠀⠘⠕⢄⠀⠀⠀⠀⠀\n"
                         "⠀⠀⠀⢀⠞⠀⠀⢀⣠⣿⣧⣀⠀⠀⢄⠱⡀⠀⠀⠀\n"
                         "⠀⠀⡰⠃⠀⠀⢠⣿⠿⣿⡟⢿⣷⡄⠀⠑⢜⢆⠀⠀\n"
                         "⠀⢰⠁⠀⠀⠀⠸⣿⣦⣿⡇⠀⠛⠋⠀⠨⡐⢍⢆⠀\n"
                         "⠀⡇⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣦⡀⠀⢀⠨⡒⠙⡄\n"
                         "⢠⠁⡀⠀⠀⠀⣤⡀⠀⣿⡇⢈⣿⡷⠀⠠⢕⠢⠁⡇\n"
                         "⠸⠀⡕⠀⠀⠀⢻⣿⣶⣿⣷⣾⡿⠁⠀⠨⣐⠨⢀⠃\n"
                         "⠀⠣⣩⠘⠀⠀⠀⠈⠙⣿⡏⠁⠀⢀⠠⢁⡂⢉⠎⠀\n"
                         "⠀⠀⠈⠓⠬⢀⣀⠀⠀⠈⠀⠀⠀⢐⣬⠴⠒⠁⠀⠀\n"
                         "⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀";
            std::cout << "\nTerk edilmiş bir gezegende yerde "<<money<< " altın buldun! Şanslı günündesin!\n\n";
            earnMoney(money); //!!!!!!!
        } else {
            std::cout << "\nTerk edildiğini sandığın gezegene geldiğinde yanıldığını anladın ve...\n\n";
            pirates();
        }
    }

    void Spaceships::pirates(void) { //3 secenek kac savas pazarlık
        std::cout << "     _                      _______                      _\n"
                     "  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_\n"
                     " dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb\n"
                     " V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~      V\n"
                     "          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'\n"
                     "           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'\n"
                     "      __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __\n"
                     "    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.\n"
                     " _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb._\n"
                     "\n"
                     "             `YMMMM\\`OOOo     OOO     oOOO'/MMMMP'\n"
                     "     ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.\n"
                     "   ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.\n"
                     "  ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM.\n"
                     "  MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM\n"
                     "  YMb           ~YMMMM\\`OOOOI`````IOOOOO'/MMMMP~           dMP\n"
                     "   `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'\n"
                     "     `'                  `OObNNNNNdOO'                   `'\n"
                     "                           `~OOOOO~'         ";
        if (fuel >= 33) {
            std::cout << "\nUzay korsanlarıyla karşılaştın! Kaç (0), savaş (1) ya da pazarlık et (2)!\n";
            int choice{0};
            std::cin >> choice;
            switch (choice) {
                case 0: //kac
                    run();
                    break;
                case 1: //savas
                    fight();
                    break;
                case 2: //pazarlik et
                    debate();
                    break;
                default:
                    std::cout << "Sadece 3 seçeneğin var!\n\n";
                    pirates();
                    break;

            }
        } else if (fuel < 33) {
            std::cout
                    << "\nUzay korsanlarıyla karşılaştın! Kaçmak için yeterli yakıtın yok. Savaş (1) ya da pazarlık et (2)!\n";
            int choice{1};
            std::cin >> choice;
            switch (choice) {
                case 1: //savas
                    fight();
                    break;
                case 2: //pazarlik et
                    debate();
                    break;
                default:
                    std::cout << "Sadece 2 seçeneğin var!\n\n";
                    pirates();
                    break;
            }
            displayStatus();
        }
    }

    void Spaceships::debate(void) {
        if (money <= 0) {
            std::cout << "Pazarlık etmek için cebinde beş kuruş olmadığını fark ettin.\n\n";
            pirates();
        } else {
            loseMoney();
        }
    }

    //DISPLAY
    void Spaceships::displayStatus() const {
        std::cout << "Gemi sağlığı: " << health << " Depodaki yakıt: " << fuel << " Toplam altın: " << money << "\n";
    }

    //GAME ENDING
    void Spaceships::puan_hesabi() {
        std::cout << "Oyun sona erdi. Puanınız :" << ((fuel * 5) + (health * 10) + (money * 10));
    }
    void Spaceships::run(void) {
        int oddsOfFlee =  (rand() % 4) == 0&1&2 ? 10: 0;
        if(oddsOfFlee>0) {
            updateFuel();// hocam kacamasa bile yakit harcanir seklinde yaptik
            std::cout<<"Yakıtın azaldı. Tam kaçabildiğini sandığın anda...\n\n";
            pirates();
        }
        else {
            updateFuel();
            std::cout<<"Korsanlara izini kaybettirdin! Yakıtın azaldı.\n\n";
        }
    }

    void Spaceships::fight(void) {
        int oddsOfWin = (rand() % 4) == 0&&1 ? 10 : 0;
        if (oddsOfWin>0) {
            std::cout<<"Savaşın galibi sensin!\n\n";
        }
        else {
            std::cout<<"Savaşı kaybettin. 15 hasar aldın.\n\n";
            GetDemage(15);
        }
    }