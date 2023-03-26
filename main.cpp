#include <iostream>
#include <vector>

enum TypeOfRoom {
    bedroom,
    kitchen,
    bathroom,
    childrenRoom,
    livingRoom
};

struct Room {
    double area;
    TypeOfRoom typeOfRoom;
};

struct Floor {
    double height;
    std::vector<Room> rooms;
};

struct Bath {
    double area;
};

struct Garage {
    double area;
};

struct House {
    double area;
    std::vector<Floor> floors;
};

struct Section {
    int id;
    House house;
    Garage garage;
    Bath bath;
};

struct Village {
    std::vector<Section> sections;
};

int main() {
    Village village;
    int sections;
    std::cout << "Введите общее количество участков: ";
    std::cin >> sections;

    for (int i = 0; i < sections; i++) {
        village.sections.push_back(Section());
        village.sections[i].id = i + 1;
        std::cout << "Введите данные про секцию #" << i + 1 << ": \n";
        std::cout << "Площадь дома: ";
        std::cin >> village.sections[i].house.area;

        int floorsCount;
        std::cout << "Этажей в доме: ";
        std::cin >> floorsCount;
        for (int j = 0; j < floorsCount; ++j) {
            village.sections[i].house.floors.push_back(Floor());
            std::cout << "Высота для этажа #" << j + 1 << ": ";
            std::cin >> village.sections[i].house.floors[j].height;

            int roomsCount;
            std::cout << "Комнат на этом этаже: ";
            std::cin >> roomsCount;
            for (int k = 0; k < roomsCount; ++k) {
                std::cout << "Какая " << k + 1 << " комната?: \n";
                std::cout << "1 - Спальня\n";
                std::cout << "2 - Кухня\n";
                std::cout << "3 - Ванная\n";
                std::cout << "4 - Детская\n";
                std::cout << "5 - Гостиная\n";

                int number;
                std::cin >> number;

                village.sections[i].house.floors[j].rooms.push_back(Room());

                switch (number) {
                    case 1:
                        village.sections[i].house.floors[j].rooms[k].typeOfRoom = bedroom;
                        break;
                    case 2:
                        village.sections[i].house.floors[j].rooms[k].typeOfRoom = kitchen;
                        break;
                    case 3:
                        village.sections[i].house.floors[j].rooms[k].typeOfRoom = bathroom;
                        break;
                    case 4:
                        village.sections[i].house.floors[j].rooms[k].typeOfRoom = childrenRoom;
                        break;
                    case 5:
                        village.sections[i].house.floors[j].rooms[k].typeOfRoom = livingRoom;
                        break;
                    default:
                        break;
                }

                std::cout << "Площадь этой комнаты: ";
                std::cin >> village.sections[i].house.floors[j].rooms[k].area;
            }
        }
        std::cout << "Площадь гаража: ";
        std::cin >> village.sections[i].garage.area;

        std::cout << "Площадь бани: ";
        std::cin >> village.sections[i].bath.area;
    }
}