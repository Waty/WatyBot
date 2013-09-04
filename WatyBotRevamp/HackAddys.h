#define DojangAddy 0xC7F820 //8B 01 8B 50 ? FF D2 8B 88 ? ? ? ? 51 05 ? ? ? ? 50 E8 ? ? ? ? 83 C4 ? - addy is at the call
#define DojangCall 0xD54CD0
#define IceGuardAddy 0xCD50B0
#define IceGuardPush 0xF51D8B //The push 1 line below the Addy
#define AggroAddy 0xD63766
#define AggroCall 0xD5ABE0
#define PinTyperAddy1 0x6D1CB6
#define PinTyperAddy2 0x6D33D7
#define PicTyperAddy1 0x8906F6 //0F 84 ? ? ? ? 6A ? 6A ? 51 8B C4
#define PicTyperAddy2 0x88FCE3
#define PicTyperAddy3 0x88FD02
#define PicTyperCall 0x5107D0
#define FusionAddy 0x75B394
#define PerfectLootAddy1 0x4C4E47
#define PerfectLootAddy2 0x55F2E5
#define PerfectLootAddy3 0x44C3D9
#define NoBGAddy1 0x88FD02
#define NoBGAddy2 0x6FE86B
#define FasterMobsAddy 0x774623
#define UnlimitedMorphAddy1 0xCF289F
#define UnlimitedMorphAddy2 0xCF33AE
#define gNDAddy1 0xCB47B3
#define gNDAddy2 0xERROR
#define JDAAddy1 0xC8E4B7
#define JDAAddy2 0xC8E4F4
#define JDAAddy3 0xC8E512
#define MobDisarmAddy 0x7587FA
#define NoMobsAddy 0x75D7CD //77 ? 0F B6 80 ? ? ? 00 FF 24 85 ? ? ? 00 8B 54 24 ? 52 E8 ? ? ? FF C2 08 00 - 2nd result
#define AirLootAddy 0x560439
#define VacRightAddy 0xD54A30
#define WalkRightAddy 0xD605CB
#define JumpRightAddy 0xD60ACF
#define NoKBAddy 0x9029AB
#define SitHackAddy 0xC844C1
#define SPControlAddy 0xCAD863
#define SPCChecksAddy 0xCAD870
#define Godmode50SecAddy1 0xCD6E8F
#define Godmode50SecAddy2 0xCD6EAA
#define LogoSkipperAddy 0x112B4A8
#define ItemVacAddy 0x71DC84 //e8 ? ? ? ? 8b c8 8b 44 24 ? 89 38  -7th Result
#define ItemVacCall 0x732AA0
#define ViewSwearsAddy 0x8FF16B
#define FMAAddy 0x75B384
#define ScareMobsAddy 0x7592FF
#define FLACC 0xD54BAA
#define CPUAddy1 0x60CA71 //RemoveObjectsAddy
#define CPUAddy2 0xERROR
#define CPUAddy3 0xERROR
#define UAAddy 0x4EB4EF //89 38 5F 89 48 04 5E C2 ? ? CC - 3rd result
#define DFAAddy 0x8320C2
#define NDMiningAddy1 0xC8B522
#define NDMiningAddy2 0xC8B5FB
#define NDMiningAddy3 0xC9DC77
#define HideDamageAddy1 0x46C69B
#define HideDamageAddy2 0x738184
#define HideDamageAddy3 0x72F7C7
#define HideDamageAddy4 0x72F7D4
#define HideDamageAddy5 0x72F7EF
#define MercedesComboAddy 0x41304B
#define ExitCSAddy 0x919A90 //75 15 57 FF 15 ? ? ? ? 3B F3 74 0A 8B 16 8B 02 6A 01 8B CE FF d0 8b 4c 24 ? 64 89 0D 00 00 00 00 -4th Result MemoryView below: mov fs:[00000000],ecx
#define ExitCSCall 0xFB0084 //See ExitCSAddy
#define NoCCBoxesAddy1 0x58A48E
#define NoCCBoxesAddy2 0x58AE93
#define FadeAddy1 0x892DC0 //6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 55 56 57 A1 ? ? ? ? 33 C4 50 8D 44 24 ? 64 A3 ? ? ? ? A1 ? ? ? ? - 4h result
#define FadeAddy2 0x893270
#define MouseFlyAddy 0xCD1E29
#define MouseFlyCall1 0xD11820 //Opcode
#define MouseFlyCall2 0x732AA0
#define CCAddy 0x58A3C0 //CField::SendTransferChannelRequest
#define CSAddy 0xDB1C70 //lpfnCWvsContext::SendMigrateToShopRequest
#define SendPacketHookAddy 0x427620 //8B 44 24 04 8B 0D ? ? ? ? 50 E8 ? ? ? ? C3 - 2nd result, check if it ends with a call to SendPacketAddy
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
#define HPAlertOffset 0x5C
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
#define SendPacketAddy 0x4D96B0
#define SendClassAddy 0x49DB77
#define ClientSocketAddy 0x49DB77
#define MSCRCAddy 0xE72C52
