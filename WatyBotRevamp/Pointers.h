#define CharBasePtr 0x1400650
#define AttackCountOffset 0x7D60
#define AttackXOffset 0x7D58
#define BuffCountOffset 0x7D70
#define BreathOffset 0x648
#define ItemIDOffset 0x7A78
#define XOffset 0x8B64
#define ComboOffset 0x8D30
#define PetOffset 0x5D08
#define Pet1Offset 0x4
#define PetFull 0xB4
 
#define InfoBasePtr 0x140A578
#define MapIDOffset 0xF78
#define CharXOffset 0xE44
 
#define StatsBasePtr 0x1405028
#define HPOffset 0x1E9C
#define MPOffset (HPOffset + 4)
#define EXPOffset 0x1DC8
 
#define MouseBasePtr 0x1405540
#define MouseLocOffset 0x978
#define MouseXOffset 0x8C
#define MouseAniOffset 0x98
 
#define SettingsBasePtr 0x1404D5C
#define HPAlertOffset 0x5C
#define MPAlertOffset 0x60
 
#define ServerBasePtr 0x1400370
#define TubiOffset 0x213C
#define WorldOffset 0x20C0
#define ChannelOffset 0x20C8
 
#define MobBasePtr 0x1404D64
#define MobCountOffset 0x10
 
#define PeopleBasePtr 0x1404D60
#define PeopleCountOffset 0x18
 
#define ItemBasePtr 0x140A194
#define ItemCountOffset 0x14
 
//#define PortalBasePtr 0x014526BC
//#define PortalCountOffset 0xC
 
#define SendAddy 0x4DA740
#define SendClassAddy 0x0049AFC7
#define ClientSocketAddy 0x014483B0

//Outdated start
#define KBOffset 0x124
#define KBXOffset (KBOffset + 0x0C)
#define KBYOffset (KBOffset + 0x14)
//Outdated end

#define MSCRCAddy 0xEAF4C2 // 8a 11 80 c2 ? 8b 4d ? 8b 09
#define WallBasePtr 0x1404C74 // 8B 0D ? ? ? ? E8 ? ? ? ? 89 44 24 ? E8 ? ? ? ? 8D 8E ? ? ? ? 50
#define CharpIDOffset 0x3108  //8B 86 ? ? ? ? 6A ? 6A ? 51 8B CC 89 64 24 ? 89 01 85 C0 74 ? 8B 08 8B 51 ? 50 FF D2 8B 4C 24 ? 8B 86 ? ? ? ? 85 C9
