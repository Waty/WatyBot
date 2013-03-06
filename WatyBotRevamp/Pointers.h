#define CharBasePtr 0x011E2228
#define AttackCountOffset 0x7034
#define AttackXOffset 0x702C
#define BuffCountOffset 0x7044
#define BreathOffset 0x638
#define ItemIDOffset 0x6D60
#define XOffset 0x7B58
#define ComboOffset 0x7CD0
#define PetOffset 0x5050
#define Pet1Offset 0x4
#define PetFullness 0xB4
#define pIDOffset 0x29D8								// 8B 87 ? ? ? ? 55 55 51 8B CC 89 64 24 ? 89 01

#define KnockBackOffset 0x130
#define KnockBackXOffset (KnockBackOffset + 0xC)
#define KnockBackYOffset (KnockBackOffset + 0x10)
 
#define InfoBasePtr 0x011EB3A8
#define MapIDOffset 0xC9C // new aob so could be wrong
#define CharXOffset 0xB68
 
#define StatsBasePtr 0x011E6BC8
#define HPOffset 0x18D8
#define MPOffset 0x18DC
#define EXPOffset 0x1808 //new aob so could be wrong
 
#define MouseBasePtr 0x011E6FE8
#define MouseLocOffset 0x978
#define MouseXOffset 0x8C
#define MouseAniOffset 0x9CC
 
#define SettingsBasePtr 0x011E68FC
#define HPAlertOffset 0x5C
#define MPAlertOffset 0x60
 
#define ServerBasePtr 0x011E1F70
#define TubiOffset 0x2124
#define WorldOffset 0x20A8
#define ChannelOffset 0x20B0
 
#define WallBasePtr 0x011E6824
#define LeftWallOffset 0x1C
 
#define MobBasePtr 0x011E6904
#define MobCountOffset 0x10
 
#define PeopleBasePtr 0x011E6900
#define PeopleCountOffset 0x18
 
#define ItemBasePtr 0x011EB064
#define ItemCountOffset 0x14
 
 
#define SendAddy 0x004C9C20
#define SendClassAddy 0x00490777
#define ClientSocketAddy 0x011E2318
 