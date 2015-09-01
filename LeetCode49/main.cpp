#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

//方法一：出现Time Limited Exceed异常
//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		if (strs.empty())
//			return vector<vector<string> >();
//
//		int len = strs.size();
//
//		vector<vector<string> > ret;		
//
//		for (int i = 0; i < len; i++)
//		{
//			vector<string > sv; 
//			string tmp1 = strs[i];
//			sv.push_back(tmp1);
//
//			sort(tmp1.begin(), tmp1.end());
//			for (int j = i + 1; j < len ; j++)
//			{
//				string tmp2 = strs[j];
//				sort(tmp2.begin(), tmp2.end());
//
//				if (tmp1 == tmp2)
//				{
//					sv.push_back(strs[j]);
//					//将处理后的元素赋值为空
//					strs[j] = "";
//				}
//			}//for
//			
//			//按字典排序该序列
//			sort(sv.begin(), sv.end());
//			//添加到结果vector
//			ret.push_back(sv);
//
//		}//for
//		return ret;
//	}
//};

//方法二：利用哈希的思想
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty())
			return vector<vector<string> >();
			
		int len = strs.size();
		
		//将字符串数组按照字典顺序排序
		sort(strs.begin(), strs.end());

		//存储结果
		vector<vector<string> > ret;

		//利用哈希思想构建map，将排序后相等的字符串存在相应的vector
		map<string, vector<string>> mv;

		for (int i = 0; i < len; i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());

			mv[str].push_back(strs[i]);
		}

		for (map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)
			ret.push_back(iter->second);

		return ret;
	}
};

int main()
{
	/*vector<string > v = {"incentive", "countersink", "pickaxing", "explicit", "unethical", 
		"seoul", "gyrates", "dismounting", "dartboard", "socialism", "sissiest", "radiotherapist", 
		"sprawl", "hems", "raggedier", "conscripted", "repealed", "implanted", "coverage", "traitorous", 
		"barmaid", "pointier", "huntress", "summers", "finnish", "mouthed", "mamore", "lemur", "osteoporosis",
		"frowziest", "sop", "comical", "speedup", "oasis", "peon", "testers", "stances", "chuckles", "childes", 
		"consensuses", "rastafarian", "battlement", "christies", "urbanized", "penitence", "replenishment", "disperse",
		"kibosh", "combatting", "repealing", "guise", "grassiest", "grafts", "waddle", "pigsties", "moneymaking", "polite",
		"reprogramming", "audaciously", "gorier", "blaze", "yaqui", "racially", "inc", "reupholstering", "fez", "lemaitre",
		"nineties", "pedal", "deferred", "tranquil", "surveyor", "narrow", "hopper", "solemnize", "federate", "trisecting",
		"cravat", "lille", "biography", "land", "jazzing", "rhomboids", "nudes", "mundanely", "greenbacks", "chattel", 
		"deceleration", "devoting", "itemizing", "routing", "jukebox", "passkey", "infants", "prerecorded", "fuzzing",
		"gandhi", "roseate", "bandit", "prong", "bowels", "bounciest", "misdeeds", "unseemliness", "emceed", "later", 
		"hailed", "crotchet", "steepness", "jot", "improves", "eucharistic", "natalia", "exalt", "performers", "predictor", 
		"voyeurism", "fedex", "activate", "crypt", "magics", "treats", "viewed", "chauffeur", "ladybug", "peppiest", "seismic",
		"microscopes", "liners", "wraps", "footman", "tape", "daubers", "aerial", "sparer", "politic", "shamed", "decal", 
		"ayrshire", "ruggeder", "washcloths", "neurologists", "singsong", "kaitlin", "conn", "monopolizes", "sunroof", 
		"zonked", "overall", "celsius", "fins", "caparison", "imus", "enfranchises", "microns", "promulgates",
		"aspartame", "fails", "decamps", "spiciness", "impieties", "starring", "receded", "skying", "suetonius",
		"pornographers", "intellectualized", "truckled", "abdications", "openness", "principally", "sellers", "complaining",
		"jeopardizing", "concerto", "fibula", "cliffs", "aorta", "inhale", "transgressions", "copywriter", "understands", 
		"coccis", "disperses", "fraying", "strengths", "macaulay", "mitigation", "competences", "ides", "linked", "tawnier", 
		"hallucinate", "dairymen", "puffier", "matchless", "wheeling", "drily", "nephews", "clandestinely", "tsingtao", "disarraying",
		"headier", "experts", "yippee", "repellent", "tributary", "clannish", "dumpsters", "genealogies", "ballooned", "denouements", "hymned", "length", "sasses", "uncontrollably", "fortune", "wastefully", "overproducing", "sickening", "headboard", "burrs", "prohibits", "keogh", "outs", "lamer", "repressed", "rowdyism", "transgressed", "euros", "amenity", "garfunkel", "rather", "noseys", "lampoons", "raja", "impermanence", "heaters", "shakespeareans", "judiciaries", "tweaked", "extrapolations", "succeeded", "jowls", "vociferation", "roadways", "herb", "inactivity", "registrars", "checks", "deservedly", "heehaws", "apologetics", "fatness", "aced", "promote", "atriums", "deidre", "redound", "litterbug", "barehanded", "scheduled", "flakiest", "twirler", "graduated", "coccus", "gadfly", "unforeseeable", "emendation", "woodsman", "wiriest", "tangelo", "weakening", "intimidating", "sternness", "reiteration", "wicca", "heresies", "inches", "encodes", "sidebar", "starking", "wastelands", "pepsi", "emigrate", "stuttgart", "shindigs", "pansy", "chintzy", "limbo", "disbarred", "gallivant", "hallmarked", "respiratory", "eminences", "unabated", "affirms", "twinned", "wordiness", "installing", "donn", "westerly", "interfaces", "benton", "mussy", "identical", "sulfates", "starvings", "woodwork", "hyphenated", "catechizing", "transition", "dramatist", "demilitarize", "buber", "spoonful", "laconic", "undervaluing", "inestimably", "severer", "improvidence", "stoneware", "cholera", "peru", "rearm", "recluses", "diaz", "tablespoonsful", "sandals", "cinderella", "insubordination", "sires", "stern", "jeremiah", "snowbound", "ramifies", "lexicographer", "skimpiest", "predetermining", "lapidary", "dentists", "upbeats", "marketplace", "ploughs", "esteem", "miserably", "overreaction", "unlikelihood", "kinswoman", "averts", "remonstrating", "asinine", "amortize", "wasps", "coal", "tenderfoot", "subplot", "coyotes", "sauntering", "rices", "fraughts", "decoded", "millipedes", "knocking", "homework", "furor", "expansionists", "j", "emergency", "sharon", "provisoes", "president", "assuaging", "curtail", "indigestion", "liming", "cryptozoic", "auguring", "indenture", "magisterially", "groped", "ensue", "steaming", "mutinous", "incomplete", "yuletide", "nomenclatures", "hundredth", "jimmies", "irk", "common", "wetly", "volley", "summary", "obsequies", "granola", "forests", "allege", "informal", "shapeless", "earplugs", "disunite", "insinuations", "junked", "riverbeds", "georgian", "brushed", "sequenced", "bucketfuls", "spiel", "humors", "screwed", "capitulating", "downturns", "intimidates", "refueling", "mingled", "arisen", "dragnet", "aftereffects", "practised", "obduracy", "canon", "penning", "inflammatory", "wisher", "actuate", "kari", "actuating", "reupholstered", "successes", "inborn", "canvasbacks", "incapacitated", "aristocratic", "britt", "lazying", "hymnals", "tyroes", "tamper", "graduate", "franc", "seasons", "pompom", "throeing", "deviate", "leveling", "inaccurate", "impaling", "trouping", "restoring", "deduces", "perforating", "artie", "alleghenies", "crusader", "rosemary", "chastest", "educational", "caveatting", "ablest", "doorstepped", "strange", "eccentricities", "sublimity", "afire", "humbugging", "jots", "ordinary", "foyer", "kayak", "snake", "wheal", "dispensations", "transponders", "zing", "pit", "meowing", "improved", "crowd", "nonfatal", "epsilon", "nodding", "cyclones", "imbibed", "rebroadcasting", "quibbles", "moisturizes", "zippy", "braille", "visaing", "abetters", "lurked", "snafus", "moppet", "lemon", "wifeliest", "stuarts", "boyish", "reapportion", "kneecaps", "stymying", "villagers", "obscenity", "bumble", "zeroing", "objectionably", "connolly", "memorial", "clanging", "gallstones", "dibbled", "outlasting", "mendez", "reproaching", "antagonized", "sisterhoods", "hunchbacks", "superimposed", "siphon", "professionally", "spermicides", "lebanon", "facing", "pierces", "philosophically", "mcdowell", "rotated", "tic", "correspondents", "nonplussed", "litchi", "ascots", "millennial", "booked", "immunize", "prefabricate", "spumoni", "odyssey", "fey", "bunched", "olen", "regularizing", "superconductors", "aside", "infirmary", "allaying", "saturdays", "caucasian", "doreen", "france", "speeding", "wretched", "slovakia", "chiselled", "peseta", "tho", "gales", "loincloths", "shock", "readers", "boarder", "entryway", "toning", "transitively", "preponderances", "internships", "rating", "pelleting", "audition", "amusement", "theed", "cocked", "toddler", "rusty", "kinfolk", "frames", "gorgonzola", "overrate", "lightweight", "bayous", "populists", "insensible", "bandoliers", "travelogs", "tactically", "weatherproofs", "sleigh", "develops", "oxygenate", "relaid", "mimi", "wheezier", "chill", "salween", "theatre", "vitalizes", "nun", "olives", "offings", "tricycling", "tipper", "kindly", "bellies", "sixteenths", "ganglia", "recombining", "eastward", "minestrone", "fairgrounds", "undelivered", "scapula", "breadth", "groupie", "ophelia", "adrenaline", "dork", "autographing", "watersides", "sent", "socks", "somnolence", "systematize", "signings", "rachmaninoff", "santa", "snacks", "leno", "spurs", "heliotropes", "silenced", "roundhouses", "illegitimacy", "hedgehog", "wet", "depressed", "eris", "pure", "pouncing", "obtuseness", "caulk", "openly", "kerosene", "grille", "buccaneers", "oar", "modals", "playacts", "shroud", "plowshares", "iciness", "retort", "jaunt", "identities", "mellower", "redesigning", "molest", "forlorner", "guacamole", "cohan", "refocus", "dossier", "interrogating", "cants", "diligence", "stomps", "enjoy", "awe", "loggerhead", "csonka", "inversions", "den", "lunged", "alkaid", "palming", "delivers", "proprietorship", "groveler", "choreographs", "instals", "merton", "cyclops", "augmentation", "manipulated", "nasal", "trousseaux", "critiques", "arenas", "stale", "suspect", "behoove", "propose", "cellulite", "purification", "leah", "polestar", "potato", "gladlier", "sunders", "entreat", "herbalist", "filthier", "skinflints", "asseverating", "insulted", "mildly", "modulate", "charges", "libyans", "weekended", "rodeos", "allegedly", "tarawa", "valedictorians", "spacy", "spontaneously", "yore", "classify", "centigrade", "videoing", "airdropping", "dejection", "pierce", "imagined", "isabel", "reiterates", "blazing", "stuck", "deceasing", "netherlands", "citric", "tormented", "monotoning", "bestowals", "betrayals", "adoptions", "scrolls", "sex", "idol", "whaler", "telephotos", "conjugation", "abductions", "bundestag", "disruptions", "nouakchott", "stuffiest", "goodly", "dissatisfying", "anglicize", "flowing", "identifying", "depots", "stoicism", "thessalonian", "hundred", "whetstone", "defroster", "headwaiter", "feisty", "inhibited", "reamed", "demonstrator", "accursed", "hector", "interchanges", "erotically", "sportscaster", "gentlewomen", "teabag", "smelts", "disorganization", "conveniently", "maugham", "hatchery", "regards", "arguably", "govern", "boulevards", "niches", "gristlier", "obtrude", "catharses", "throughway", "stoppered", "drinkers", "indeterminacy", "vacuums", "plainest", "acuff", "eases", "defined", "splurge", "severing", "griddles", "thermoplastics", "dilution", "vinegary", "straights", "testament", "sticks", "shanghai", "childproofing", "clobbers", "taco", "castro", "arrests", "fetter", "discomposing", "timbres", "wondrous", "pullmans", "amusements", "telephonic", "manning", "inhabiting", "finery", "admires", "defensively", "fiord", "incriminate", "oust", "collapse", "deliquescent", "bulwark", "consciousness", "roguery", "beefburger", "amounted", "pheasants", "archdioceses", "vote", "gujarati", "forwards", "waggling", "tanned", "liberalization", "chap", "finishing", "catawba", "anus", "farina", "butterflying", "folks", "crumple", "criticize", "unswerving", "snack", "gentrification", "enthroning", "drearies", "marietta", "farley", "recede", "incise", "electrodes", "dirac", "corn", "livest", "coughs", "noreen", "rapscallion", "codeine", "acidly", "confiscates", "dislikes", "administrators", "valid", "prep", "legated", "wherewithal", "subjugating", "wallabies", "boning", "creakiest", "erotica", "neophytes", "drowses", "bushmen", "basis", "regattas", "melancholy", "clubfeet", "there", "generalized", "rotunding", "condone", "hemlines", "bantered", "vertebral", "ruby", "companions", "postmarked", "aping", "finalized", "prado", "mutilations", "partied", "isiah", "desk", "calcines", "agreeing", "bode", "cygnet", "downsizing", "naiads", "preambled", "recife", "randall", "gillespie", "convalescent", "victories", "obsessed", "leaders", "strips", "parmesan", "germicide", "clarion", "pictograph", "nutshells", "bungalows", "hagged", "colosseum", "ferraro", "recapitulations", "labored", "acrostic", "dynamics", "bucked", "betaking", "pragmatically", "gobbed", "glossy", "congresses", "rewindable", "trout", "renovates", "mattered", "davenport", "stenographer", "nudism", "deduced", "unattributed", "equally", "wrestled", "sequoia", "measurable", "lamb", "babe", "concourses", "creamer", "fascination", "steroids", "deplaned", "germinated", "progressed", "swashbuckling", "pools", "officemax", "brewers", "banjul", "thong", "periodic", "grub", "typescript", "lemurs", "excreta", "seeps", "clearinghouses", "isolating", "particularized", "thallium", "waistcoat", "misread", "extensiveness", "violations", "insistent", "zany", "newses", "predominate", "enunciating", "ultras", "burlap", "dowelled", "elision", "person", "minneapolis", "edification", "endued", "asseverates", "meeter", "iceberg", "mexican", "end", "wale", "veronese", "ida", "earshot", "tunnels", "debuting"
		};*/

	vector<string> v = { "eat", "tea", "tan", "ate", "nat", "bat" };

	Solution s;

	vector<vector<string> > ret = s.groupAnagrams(v);

	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << "\t";
		cout << endl;
	}//for

	system("pause");
	return 0;
}
	