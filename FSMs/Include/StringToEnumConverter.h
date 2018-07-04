#pragma once
#include <string>
#include <map>
#include <set>

static std::set<std::string> s_commands =
{
	"KRYSHA",
	"VICKONAI",
	"ZAPISH",
	"POVIETZ",
	"OOSOUN",
	"NITZ",
	"GOTOVA",
	"ZAKOOPEI",
	"POKASH",
	"VITCISHTCH",
	"KNOTAUTHKA",
	"VROOTCH",
	"MAJIK",
	"SUAVJIK",
	"MLEKO",
	"MASUO",
	"HLEB",
	"VIEHPSHOVINA",
	"VOUOVINA",
	"DROUB",
	"YAYA",
	"SER",
	"BOUKI",
	"VODA",
	"WAUCOTCHIA",
	"OVOTCHEI",
	"PSHIPRAVA"
};

static std::set<std::string> s_availableShoppingList =
{
	"MLEKO",
	"MASLO",
	"CHLEB",
	"WIERZOWINA",
	"WOLOWINA",
	"DROB",
	"JAJA",
	"SER",
	"BULKI",
	"WODA",
	"LAKOCIE",
	"OWOCE",
	"PRZYPRAWA"
};

enum COMMAND
{
	KRYSIA = 1,
	WYKONAJ,
	ZAPISZ,
	POWIEDZ,
	USUN,
	NIC,
	GOTOWE,
	ZAKUPY,
	POKAZ,
	WYCZYSC,
	NOTATKA,
	WROC,
	MADZIK,
	SLAWDZIK,
};

static std::map<std::string, COMMAND> s_stringToEnumConverter
{
	{ "KRYSHA",		KRYSIA	},
	{ "VICKONAI",	WYKONAJ	},
	{ "ZAPISH",		ZAPISZ	},
	{ "POVIETZ",	POWIEDZ	},
	{ "OOSOUN",		USUN	},
	{ "NITZ",		NIC		},
	{ "GOTOVA",		GOTOWE	},
	{ "ZAKOOPEI",	ZAKUPY	},
	{ "POKASH",		POKAZ	},
	{ "VITCISHTCH",	WYCZYSC	},
	{ "KNOTAUTHKA",	NOTATKA	},
	{ "VROOTCH",	WROC	},
	{ "MAJIK",		MADZIK	},
	{ "SUAVJIK",	SLAWDZIK}
};

static std::map<COMMAND, std::string> s_enumToStringConverter
{
	{ KRYSIA,	"KRYSHA"	},
	{ WYKONAJ,	"VICKONAI"	},
	{ ZAPISZ,	"ZAPISH"	},
	{ POWIEDZ,	"POVIETZ"	},
	{ USUN,		"OOSOUN"	},
	{ NIC,		"NITZ"		},
	{ GOTOWE,	"GOTOVA"	},
	{ ZAKUPY,	"ZAKOOPEI"	},
	{ POKAZ,	"POKASH"	},
	{ WYCZYSC,	"VITCISHTCH"},
	{ NOTATKA,	"KNOTAUTHKA"},
	{ WROC,		"VROOTCH"	},
	{ MADZIK,	"MAJIK"		},
	{ SLAWDZIK,	"SUAVJIK"	}
};

static std::map<std::string, std::string> s_stringPhonemsToStringConverter
{
	{ "BOUKI",			"BULKI" 	},
	{ "DROUB",			"DROB"		},
	{ "GOTOVA",			"GOTOWE" 	},
	{ "HLEB",			"CHLEB"		},
	{ "KNOTAUTHKA",		"NOTATKA" 	},
	{ "KRYSHA",			"KRYSIA"	},
	{ "MAJIK",			"MADZIK"	},
	{ "MASUO",			"MASLO"		},
	{ "MLEKO",			"MLEKO" 	},
	{ "NITZ",			"NIC" 		},
	{ "OOSOUN",			"USUN"		},
	{ "OVOTZE",			"OWOCE"		},
	{ "POKASH",			"POKAZ" 	},
	{ "POVIETZ",		"POWIEDZ" 	},
	{ "PSHIPRAVA",		"PRZYPRAWA" },
	{ "SER",			"SER"		},
	{ "SUAVJIK",		"SLAWDZIK" 	},
	{ "VICKONAI",		"WYKONAJ" 	},
	{ "VIEHPSHOVINA",	"WIERZOWINA"},
	{ "VITCISHTCH",		"WYCZYSC"	},
	{ "VODA",			"WODA" 		},
	{ "VOUOVINA",		"WOLOWINA" 	},
	{ "VROOTCH",		"WROC" 		},
	{ "WAUCOTCHIA",		"LAKOCIE" 	},
	{ "YAYA",			"JAJA" 		},
	{ "ZAKOOPEI",		"ZAKUPY" 	},
	{ "ZAPISH",			"ZAPISZ"	}



};
