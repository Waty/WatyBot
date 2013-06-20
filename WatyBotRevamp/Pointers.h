#define CharBasePtr 0x01448298
#define AttackCountOffset 0x7D28
#define AttackXOffset 0x7D20
#define BuffCountOffset 0x7D38
#define BreathOffset 0x648
#define ItemIDOffset 0x7A50
#define XOffset 0x8B58
#define ComboOffset 0x8D28
#define PetOffset 0x5CE4
#define Pet1Offset 0x4
#define PetFull 0xB4
 
#define InfoBasePtr 0x014526D0
#define MapIDOffset 0xFA4
#define CharXOffset 0xE60
 
#define StatsBasePtr 0x0144CC80
#define HPOffset 0x1EF4
#define MPOffset 0x1EF8
#define EXPOffset 0x1E20
 
#define MouseBasePtr 0x0144D1A0
#define MouseLocOffset 0x978
#define MouseXOffset 0x8C
#define MouseAniOffset 0x98
 
#define SettingsBasePtr 0x0144C9B4
#define HPAlertOffset 0x5C
#define MPAlertOffset 0x60
 
#define ServerBasePtr 0x01447FD0
#define TubiOffset 0x213C
#define WorldOffset 0x20C0
#define ChannelOffset 0x20C8
 
#define MobBasePtr 0x0144C9BC
#define MobCountOffset 0x10
 
#define PeopleBasePtr 0x0144C9B8
#define PeopleCountOffset 0x18
 
#define ItemBasePtr 0x01451DFC
#define ItemCountOffset 0x14
 
#define PortalBasePtr 0x014526BC
#define PortalCountOffset 0xC
 
#define SendAddy 0x004D7070
#define SendClassAddy 0x0049AFC7
#define ClientSocketAddy 0x014483B0

//Outdated start
#define KBOffset 0x124
#define KBXOffset (KBOffset + 0x0C)
#define KBYOffset (KBOffset + 0x14)
//Outdated end

#define MSCRCAddy 0xEAF4C2 // 8a 11 80 c2 ? 8b 4d ? 8b 09
#define WallBasePtr 0x0144C8CC // 8B 0D ? ? ? ? E8 ? ? ? ? 89 44 24 ? E8 ? ? ? ? 8D 8E ? ? ? ? 50
#define CharpIDOffset 0x3108  //8B 86 ? ? ? ? 6A ? 6A ? 51 8B CC 89 64 24 ? 89 01 85 C0 74 ? 8B 08 8B 51 ? 50 FF D2 8B 4C 24 ? 8B 86 ? ? ? ? 85 C9
