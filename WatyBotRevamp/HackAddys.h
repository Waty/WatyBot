#define DojangAddy 0xCBEF34  //8B 01 8B 50 ? ff d2 8b 88 ? ? ? ? 51 - 6TH Result
#define DojangCall 0xD93650
#define IceGuardAddy 0xD14DC0
#define IceGuardPush 0xF90ECB //The push 1 line below the Addy
#define AggroAddy 0xDA23D6
#define AggroCall 0xD99870
#define PinTyperAddy1 0x6EB556
#define PinTyperAddy2 0x6ECC37
#define FusionAddy 0x774114
#define PerfectLootAddy1 0x4C2227
#define PerfectLootAddy2 0x55B965
#define PerfectLootAddy3 0x445C49
#define NoBGAddy1 0x718D92
#define NoBGAddy2 0x71769B
#define FasterMobsAddy 0x79BE63
#define UnlimitedMorphAddy1 0xD3268F
#define UnlimitedMorphAddy2 0xD33198
#define gNDAddy1 0xCF4423
#define gNDAddy2 0x89D928
#define JDAAddy1 0xCCDFE7
#define JDAAddy2 0xCCE024
#define JDAAddy3 0xCD6764
#define MobDisarmAddy 0x7715AA
#define NoMobsAddy 0x81595F
#define AirLootAddy 0x55CAF9
#define VacRightAddy 0xD93440
#define WalkRightAddy 0xD9F23B
#define JumpRightAddy 0xD9F73F
#define NoKBAddy 0x924A7B
#define SitHackAddy 0xCC3F81
#define SPControlAddy 0xCED4BA
#define SPCChecksAddy 0xCED4C7
#define Godmode50SecAddy1 0xD16B9F
#define Godmode50SecAddy2 0xD16BBA
#define LogoSkipperAddy 0x01177AC0
#define ItemVacAddy 0x738814 //e8 ? ? ? ? 8b c8 8b 44 24 ? 89 38  -7th Result
#define ItemVacCall 0x407DB0
#define ViewSwearsAddy 0x920CCB
#define FMAAddy 0x774104
#define ScareMobsAddy 0x7720AF
#define FLACC 0xD935BA
#define CPUAddy1 0x696C51
#define CPUAddy2 0x718D92
#define CPUAddy3 0x71DA09
#define UAAddy 0x4E8F8F //89 38 5F 89 48 04 5E C2 ? ? CC - 3rd result
#define DFAAddy 0x85D8A2
#define NDMiningAddy1 0xCCB042
#define NDMiningAddy2 0xCCB11B
#define NDMiningAddy3 0xCDD587
#define HideDamageAddy1 0x46A240
#define HideDamageAddy2 0x751B6B
#define HideDamageAddy3 0x7492BA
#define HideDamageAddy4 0x7492C7
#define HideDamageAddy5 0x7492E2
#define MercedesComboAddy 0x5CBA3A
#define CCAddy 0x5ADA20
#define ExitCSAddy 0x93B78E //75 15 57 FF 15 ? ? ? ? 3B F3 74 0A 8B 16 8B 02 6A 01 8B CE FF d0 8b 4c 24 ? 64 89 0D 00 00 00 00 -4th Result MemoryView below: mov fs:[00000000],ecx
#define ExitCSCall 0xFF2084 //See ExitCSAddy
#define NoCCBoxesAddy1 0x5ADAF4
#define NoCCBoxesAddy2 0x5B2A46
#define FadeAddy1 0x8B52A0 //6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 55 56 57 A1 ? ? ? ? 33 C4 50 8D 44 24 ? 64 A3 ? ? ? ? A1 ? ? ? ? - 4h result
#define FadeAddy2 0x8B5750
#define MouseFlyAddy 0xD11B39
#define MouseFlyCall1 0xD51480 //Opcode
#define MouseFlyCall2 0x406E40
#define SendPacketAddy 0x4D7070
#define SendPacketHookAddy 0x426B70 //8B 44 24 04 8B 0D ? ? ? ? 50 E8 ? ? ? ? C3 2nd result, check if it ends with a call to SendPacketAddy
