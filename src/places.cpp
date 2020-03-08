// places.cpp

#include "places.h"

Place Downtown("Downtown",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/downtown-day.bmp",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/downtown-night.bmp",
NULL, NULL, idDowntown, std::vector<Hotspot>());
Place WitchesBrew("Witches Brew",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/witchsbrew-day.bmp",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/witchsbrew-night.bmp",
NULL, NULL, idWitchesBrew, std::vector<Hotspot>());
Place ApartmentFull("Christine and Sarah's apartment",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/roomfull-day.bmp",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/roomfull-night.bmp",
NULL, NULL, idApartmentFull, std::vector<Hotspot>());
Place ApartmentSarah("Sarah's bed",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/roomsarah-day.bmp",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/roomsarah-night.bmp",
NULL, NULL, idApartmentSarah, std::vector<Hotspot>());
Place SalemU("Salem University",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/salemu-day.bmp",
"/home/cnsorensen/projects/twilight-in-oregon/src/images/backgrounds/salemu-night.bmp",
NULL, NULL, idSalemU, std::vector<Hotspot>());

int PlacesCount = 5;
Place Places[5] = {Downtown, WitchesBrew, ApartmentFull, ApartmentSarah, SalemU};
