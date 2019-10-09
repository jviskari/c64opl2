#ifndef _VGM_TYPES_H_
#define _VGM_TYPE_H_H

#include <stdint.h>

//typedef uint16_t wchar_t;

typedef struct _vgm_file_header
{
	uint32_t fccVGM;
	uint32_t lngEOFOffset;
	uint32_t lngVersion;
	uint32_t lngHzPSG;
	uint32_t lngHzYM2413;
	uint32_t lngGD3Offset;
	uint32_t lngTotalSamples;
	uint32_t lngLoopOffset;
	uint32_t lngLoopSamples;
	uint32_t lngRate;
	uint16_t shtPSG_Feedback;
	uint8_t bytPSG_SRWidth;
	uint8_t bytPSG_Flags;
	uint32_t lngHzYM2612;
	uint32_t lngHzYM2151;
	uint32_t lngDataOffset;
	uint32_t lngHzSPCM;
	uint32_t lngSPCMIntf;
	uint32_t lngHzRF5C68;
	uint32_t lngHzYM2203;
	uint32_t lngHzYM2608;
	uint32_t lngHzYM2610;
	uint32_t lngHzYM3812;
	uint32_t lngHzYM3526;
	uint32_t lngHzY8950;
	uint32_t lngHzYMF262;
	uint32_t lngHzYMF278B;
	uint32_t lngHzYMF271;
	uint32_t lngHzYMZ280B;
	uint32_t lngHzRF5C164;
	uint32_t lngHzPWM;
	uint32_t lngHzAY8910;
	uint8_t bytAYType;
	uint8_t bytAYFlag;
	uint8_t bytAYFlagYM2203;
	uint8_t bytAYFlagYM2608;
	uint8_t bytVolumeModifier;
	uint8_t bytReserved2;
	int8_t bytLoopBase;
	uint8_t bytLoopModifier;
	uint32_t lngHzGBDMG;
	uint32_t lngHzNESAPU;
	uint32_t lngHzMultiPCM;
	uint32_t lngHzUPD7759;
	uint32_t lngHzOKIM6258;
	uint8_t bytOKI6258Flags;
	uint8_t bytK054539Flags;
	uint8_t bytC140Type;
	uint8_t bytReservedFlags;
	uint32_t lngHzOKIM6295;
	uint32_t lngHzK051649;
	uint32_t lngHzK054539;
	uint32_t lngHzHuC6280;
	uint32_t lngHzC140;
	uint32_t lngHzK053260;
	uint32_t lngHzPokey;
	uint32_t lngHzQSound;
	uint32_t lngHzSCSP;
//	uint32_t lngHzOKIM6376;
	//uint8_t bytReserved[0x04];
	uint32_t lngExtraOffset;
	uint32_t lngHzWSwan;
	uint32_t lngHzVSU;
	uint32_t lngHzSAA1099;
	uint32_t lngHzES5503;
	uint32_t lngHzES5506;
	uint8_t bytES5503Chns;
	uint8_t bytES5506Chns;
	uint8_t bytC352ClkDiv;
	uint8_t bytESReserved;
	uint32_t lngHzX1_010;
	uint32_t lngHzC352;
	uint32_t lngHzGA20;
} VGM_HEADER;
typedef struct _vgm_header_extra
{
	uint32_t DataSize;
	uint32_t Chp2ClkOffset;
	uint32_t ChpVolOffset;
} VGM_HDR_EXTRA;
typedef struct _vgm_extra_chip_data32
{
	uint8_t Type;
	uint32_t Data;
} VGMX_CHIP_DATA32;
typedef struct _vgm_extra_chip_data16
{
	uint8_t Type;
	uint8_t Flags;
	uint16_t Data;
} VGMX_CHIP_DATA16;
typedef struct _vgm_extra_chip_extra32
{
	uint8_t ChipCnt;
	VGMX_CHIP_DATA32* CCData;
} VGMX_CHP_EXTRA32;
typedef struct _vgm_extra_chip_extra16
{
	uint8_t ChipCnt;
	VGMX_CHIP_DATA16* CCData;
} VGMX_CHP_EXTRA16;
typedef struct _vgm_header_extra_data
{
	VGMX_CHP_EXTRA32 Clocks;
	VGMX_CHP_EXTRA16 Volumes;
} VGM_EXTRA;

#define VOLUME_MODIF_WRAP	0xC0
typedef struct _vgm_gd3_tag
{
	uint32_t fccGD3;
	uint32_t lngVersion;
	uint32_t lngTagLength;
	wchar_t* strTrackNameE;
	wchar_t* strTrackNameJ;
	wchar_t* strGameNameE;
	wchar_t* strGameNameJ;
	wchar_t* strSystemNameE;
	wchar_t* strSystemNameJ;
	wchar_t* strAuthorNameE;
	wchar_t* strAuthorNameJ;
	wchar_t* strReleaseDate;
	wchar_t* strCreator;
	wchar_t* strNotes;
} GD3_TAG;
typedef struct _vgm_pcm_bank_data
{
	uint32_t DataSize;
	uint8_t* Data;
	uint32_t DataStart;
} VGM_PCM_DATA;
typedef struct _vgm_pcm_bank
{
	uint32_t BankCount;
	VGM_PCM_DATA* Bank;
	uint32_t DataSize;
	uint8_t* Data;
	uint32_t DataPos;
	uint32_t BnkPos;
} VGM_PCM_BANK;

#define FCC_VGM	0x206D6756	// 'Vgm '
#define FCC_GD3	0x20336447	// 'Gd3 '

#endif