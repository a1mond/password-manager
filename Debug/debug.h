#ifndef PASSWORD_MANAGER_V2_DEBUG_H
#define PASSWORD_MANAGER_V2_DEBUG_H
#include "../Consts/Consts.h"

static void debugEntries() {
    vars::user_map.try_emplace("Almond", User{"Almond", "lashped"});
    vars::user_map.try_emplace("Dedaio", User{"DRoauhfa", "laagfadsasda"});
    vars::user_map.try_emplace("OSUBNF", User{"OHGUAIEH", "ssrgsradaa"});
    vars::user_map.at("Almond").addPassword("whatsapp", "loh");
    vars::user_map.at("Almond").addPassword("telegram", "aoifae");
    vars::user_map.at("Almond").addPassword("insta", "apiejfie");
    vars::user_map.at("Almond").addPassword("koaief", "paiejfijao");
};

#endif //PASSWORD_MANAGER_V2_DEBUG_H
