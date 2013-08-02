#define DojangAddy 0xC7F4C4 //8B 01 8B 50 14 FF D2 8B 88 ? ? ? ? 51 05 ? ? ? ? 50 E8 ? ? ? ? 83 C4 08 F7 D8 1B C0 F7 D8 C3 - check call
#define DojangCall 0xD54AA0
#define IceGuardAddy 0xCD4DC0
#define IceGuardPush 0xF51B3B //The push 1 line below the Addy
#define AggroAddy 0xD63426
#define AggroCall 0xD5A8B0
#define PinTyperAddy1 0x6D2576
#define PinTyperAddy2 0x6D3C97
#define PicTyperAddy1 0x8912D6
#define PicTyperAddy2 0x8908C3
#define PicTyperAddy3 0x8908E2
#define FusionAddy 0x75C184
#define PerfectLootAddy1 0x4C51C7
#define PerfectLootAddy2 0x55F2F5
#define PerfectLootAddy3 0x44BE69
#define NoBGAddy1 0x700CF0
#define NoBGAddy2 0x6FF6DB
#define FasterMobsAddy 0x775543
#define UnlimitedMorphAddy1 0xCF257F
#define UnlimitedMorphAddy2 0xCF308E
#define gNDAddy1 0xCB44C3
#define gNDAddy2 0xERROR
#define JDAAddy1 0xC8E3B7
#define JDAAddy2 0xC8E3F4
#define JDAAddy3 0xC8E412
#define MobDisarmAddy 0x75960A
#define NoMobsAddy 0x75E5BD
#define AirLootAddy 0x5604A9
#define VacRightAddy 0xD54800
#define WalkRightAddy 0xD6028B
#define JumpRightAddy 0xD6078F
#define NoKBAddy 0x90309B
#define SitHackAddy 0xC84331
#define SPControlAddy 0xCAD593
#define SPCChecksAddy 0xCAD5A0
#define Godmode50SecAddy1 0xCD6B9F
#define Godmode50SecAddy2 0xCD6BBA
#define LogoSkipperAddy 0x112A648
#define ItemVacAddy 0x71EE14 //e8 ? ? ? ? 8b c8 8b 44 24 ? 89 38  -7th Result
#define ItemVacCall 0x7338D0
#define ViewSwearsAddy 0x8FF84B
#define FMAAddy 0x75C174
#define ScareMobsAddy 0x75A10F
#define FLACC 0xD5497A
#define CPUAddy1 0x60D2F1
#define CPUAddy2 0xERROR
#define CPUAddy3 0xERROR
#define UAAddy 0x4EBA1F //89 38 5F 89 48 04 5E C2 ? ? CC - 3rd result
#define DFAAddy 0x832CC2
#define NDMiningAddy1 0xC8B422
#define NDMiningAddy2 0xC8B4FB
#define NDMiningAddy3 0xC9DB77
#define HideDamageAddy1 0x46BC7B
#define HideDamageAddy2 0x738F94
#define HideDamageAddy3 0x7305D7
#define HideDamageAddy4 0x7305E4
#define HideDamageAddy5 0x7305FF
#define MercedesComboAddy 0x41325B
#define ExitCSAddy 0x91A200 //75 15 57 FF 15 ? ? ? ? 3B F3 74 0A 8B 16 8B 02 6A 01 8B CE FF d0 8b 4c 24 ? 64 89 0D 00 00 00 00 -4th Result MemoryView below: mov fs:[00000000],ecx
#define ExitCSCall 0xFAF084 //See ExitCSAddy
#define NoCCBoxesAddy1 0x58A64E
#define NoCCBoxesAddy2 0x58B053
#define FadeAddy1 0x8938E0 //6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 55 56 57 A1 ? ? ? ? 33 C4 50 8D 44 24 ? 64 A3 ? ? ? ? A1 ? ? ? ? - 4h result
#define FadeAddy2 0x893D90
#define MouseFlyAddy 0xCD1B39
#define MouseFlyCall1 0xD115D0 //Opcode
#define MouseFlyCall2 0x407920
#define CCAddy 0x58A580 //CField::SendTransferChannelRequest
#define CSAddy 0xDB1620 //lpfnCWvsContext::SendMigrateToShopRequest
#define SendPacketHookAddy 0x4277D0 //8B 44 24 04 8B 0D ? ? ? ? 50 E8 ? ? ? ? C3 - 2nd result, check if it ends with a call to SendPacketAddy
#define CharBasePtr 0x13FD650
#define AttackCountOffset 0x7D60
#define AttackXOffset 0x7D58
#define BuffCountOffset 0x7D70
#define BreathOffset 0x648
#define ItemIDOffset 0x7A78
#define XOffset 0x8B64
#define ComboOffset 0x8D30
#define PetOffset 0x5D08
#define PetFullnessOffset 0xB4
#define InfoBasePtr 0x1407578
#define MapIDOffset 0xF78
#define CharXOffset 0xE44
#define StatsBasePtr 0x1402028
#define HPOffset 0x1E9C
#define EXPOffset 0x1DC8
#define MouseBasePtr 0x1402540
#define MouseLocOffset 0x978
#define MouseXOffset 0x8C
#define MouseAniOffset 0x9DC
#define SettingsBasePtr 0x1401D5C
#define HPAlertOffset 0x5C
#define MPAlertOffset 0x60
#define ServerBasePtr 0x13FD370
#define TubiOffset 0x213C
#define WorldOffset 0x20C0
#define ChannelOffset 0x8BF
#define WallBasePtr 0x1401C74
#define MobBasePtr 0x1401D64
#define MobCountOffset 0x10
#define MobDeathOffset 0x57C
#define PeopleBasePtr 0x1401D60
#define PeopleCountOffset 0x18
#define ItemBasePtr 0x1407194
#define ItemCountOffset 0x1424
#define SendPacketAddy 0x4D99E0
#define SendClassAddy 0x49D337
#define ClientSocketAddy 0x49D337
#define MSCRCAddy 0xE72922
