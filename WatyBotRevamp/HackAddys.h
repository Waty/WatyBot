#define DojangAddy 0xC7FD04 //8B 01 8B 50 ? FF D2 8B 88 ? ? ? ? 51 05 ? ? ? ? 50 E8 ? ? ? ? 83 C4 ? - 7th result addy is at the call
#define DojangCall 0xD54F20
#define IceGuardAddy 0xCD5470
#define IceGuardPush 0xF51FAB //The push 1 line below the Addy
#define AggroAddy 0xD63D36
#define AggroCall 0xD5B1A0
#define PinTyperAddy1 0x6D2886
#define PinTyperAddy2 0x6D3FA7
#define PicTyperAddy1 0x891126 //0F 84 ? ? ? ? 6A ? 6A ? 51 8B C4
#define PicTyperAddy2 0x890713
#define PicTyperAddy3 0x890732
#define FusionAddy 0x75BBA4
#define PerfectLootAddy1 0x4C5B47
#define PerfectLootAddy2 0x55FB55
#define PerfectLootAddy3 0x44C999
#define NoBGAddy1 0x700BC0
#define NoBGAddy2 0x6FF5AB
#define FasterMobsAddy 0x775303
#define UnlimitedMorphAddy1 0xCF2C7F
#define UnlimitedMorphAddy2 0xCF378E
#define gNDAddy1 0xCB4B73
#define gNDAddy2 0xERROR
#define JDAAddy1 0xC8EA47
#define JDAAddy2 0xC8EA84
#define JDAAddy3 0xC8EAA2
#define MobDisarmAddy 0x758F6A
#define NoMobsAddy 0x75DFDD //77 ? 0F B6 80 ? ? ? 00 FF 24 85 ? ? ? 00 8B 54 24 ? 52 E8 ? ? ? FF C2 08 00 - 2nd result
#define AirLootAddy 0x560CA9
#define VacRightAddy 0xD54C80
#define WalkRightAddy 0xD60B9B
#define JumpRightAddy 0xD6109F
#define NoKBAddy 0x90364B
#define SitHackAddy 0xC849C1
#define SPControlAddy 0xCADC23
#define SPCChecksAddy 0xCADC30
#define Godmode50SecAddy1 0xCD724F
#define Godmode50SecAddy2 0xCD726A
#define LogoSkipperAddy 0x112B578
#define ItemVacAddy 0x71ECA4 //e8 ? ? ? ? 8b c8 8b 44 24 ? 89 38  -7th Result
#define ItemVacCall 0x408720
#define ViewSwearsAddy 0x8FFE0B
#define FMAAddy 0x75BB94
#define ScareMobsAddy 0x759A6F
#define FLACC 0xD54DFA
#define CPUAddy1 0x60D2B1 //RemoveObjectsAddy
#define CPUAddy2 0xERROR
#define CPUAddy3 0xERROR
#define UAAddy 0x4EC0DF //89 38 5F 89 48 04 5E C2 ? ? CC - 3rd result
#define DFAAddy 0x832E82
#define NDMiningAddy1 0xC8BAB2
#define NDMiningAddy2 0xC8BB8B
#define NDMiningAddy3 0xC9E207
#define HideDamageAddy1 0x46CF4B
#define HideDamageAddy2 0x7388F4
#define HideDamageAddy3 0x72FFB7
#define HideDamageAddy4 0x72FFC4
#define HideDamageAddy5 0x72FFDF
#define MercedesComboAddy 0x41375B
#define ExitCSAddy 0x91A740 //75 15 57 FF 15 ? ? ? ? 3B F3 74 0A 8B 16 8B 02 6A 01 8B CE FF d0 8b 4c 24 ? 64 89 0D 00 00 00 00 -4th Result MemoryView below: mov fs:[00000000],ecx
#define ExitCSCall 0xFB0088 //See ExitCSAddy
#define NoCCBoxesAddy1 0x58AC7E
#define NoCCBoxesAddy2 0x58B683
#define FadeAddy1 0x893890 //6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 55 56 57 A1 ? ? ? ? 33 C4 50 8D 44 24 ? 64 A3 ? ? ? ? A1 ? ? ? ? - 4h result
#define FadeAddy2 0x893D40
#define MouseFlyAddy 0xCD21E9
#define MouseFlyCall1 0xD11AF0 //Opcode
#define MouseFlyCall2 0x407B30
#define CCAddy 0x58ABB0 //CField::SendTransferChannelRequest
#define CSAddy 0xDB1EC0 //lpfnCWvsContext::SendMigrateToShopRequest
#define SendPacketHookAddy 0x428200 //8B 44 24 04 8B 0D ? ? ? ? 50 E8 ? ? ? ? C3 - 2nd result, check if it ends with a call to SendPacketAddy
#define CharBasePtr 0x13FE690
#define AttackCountOffset 0x7D60
#define AttackXOffset 0x7D58
#define BuffCountOffset 0x7D70
#define BreathOffset 0x648
#define ItemIDOffset 0x7A78
#define XOffset 0x8B64
#define ComboOffset 0x8D30
#define PetOffset 0x5D08
#define PetFullnessOffset 0xB4
#define InfoBasePtr 0x14085C8
#define MapIDOffset 0xF78
#define CharXOffset 0xE44
#define StatsBasePtr 0x1403068
#define HPOffset 0x1E9C
#define EXPOffset 0x1DC8
#define MouseBasePtr 0x1403580
#define MouseLocOffset 0x978
#define MouseXOffset 0x8C
#define MouseAniOffset 0x9DC
#define SettingsBasePtr 0x1402D9C
#define HPAlertOffset 0x402D
#define MPAlertOffset 0x2D9C
#define ServerBasePtr 0x13FE3B0
#define TubiOffset 0x213C
#define WorldOffset 0x20C0
#define ChannelOffset 0x8BF
#define WallBasePtr 0x1402CB4
#define MobBasePtr 0x1402DA4
#define MobCountOffset 0x10
#define MobDeathOffset 0x57C
#define PeopleBasePtr 0x1402DA0
#define PeopleCountOffset 0x18
#define ItemBasePtr 0x14081E4
#define ItemCountOffset 0x14
#define SendPacketAddy 0x4DA290
#define SendClassAddy 0x49E817
#define ClientSocketAddy 0x49E817
#define MSCRCAddy 0xE72D72
