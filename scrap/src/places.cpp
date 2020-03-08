// places.cpp

#include "places.h"

Place Downtown("Downtown",
"src/images/backgrounds/downtown-day.bmp",
"src/images/backgrounds/downtown-night.bmp",
NULL, NULL, idDowntown, std::vector<Hotspot>());
Place WitchesBrew("Witches Brew",
"src/images/backgrounds/witchsbrew-day.bmp",
"src/images/backgrounds/witchsbrew-night.bmp",
NULL, NULL, idWitchesBrew, std::vector<Hotspot>());
Place ApartmentFull("Christine and Sarah's apartment",
"src/images/backgrounds/roomfull-day.bmp",
"src/images/backgrounds/roomfull-night.bmp",
NULL, NULL, idApartmentFull, std::vector<Hotspot>());
Place ApartmentSarah("Sarah's bed",
"src/images/backgrounds/roomsarah-day.bmp",
"src/images/backgrounds/roomsarah-night.bmp",
NULL, NULL, idApartmentSarah, std::vector<Hotspot>());
Place SalemU("Salem University",
"src/images/backgrounds/salemu-day.bmp",
"src/images/backgrounds/salemu-night.bmp",
NULL, NULL, idSalemU, std::vector<Hotspot>());

int PlacesCount = 5;
Place Places[5] = {Downtown, WitchesBrew, ApartmentFull, ApartmentSarah, SalemU};
