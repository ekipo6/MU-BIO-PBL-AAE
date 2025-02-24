
Talde 6 PBL infor.

## Taldekideak

*   [1. Jon ruiz] -  [jonru22]
*   [2. Uxue Monterola] - [Uxuemanterola]
*   [3. saioa markuleta] - [saioamarku]
*   [4. emma rodriguez] - [emyy6498]
*   [5. Alazne rubio] - [AlazneRubio]

dokumentu honetan PBLren informatika-lana aztertuko dugu.

lehenengo eta behin, bideo bat grabatu eta tracker-aplikazioan sartu genuen. Bideo honetan, X eta Y ardatzetan sortu genuen; ondoren, eskala kalibratu genuen kalibrazio-makila baten bidez, eta, azkenik, masa puntual bat sortu genuen. Masa horri A. deitu genion, eta fotogramaz fotograma segimendua egin genion. Gure kasuan, 4 fotogramatik behin arakatu genuen, eta gainerakoa autorellenararekin egin genuen. Hala ere, autorellenarra ez zen beti beharrezkoa izan, eta hainbat puntu zuzendu behar izan ziren.

Nahi ditugun fotograma guztietan A masa daukagunean, T, X, Y, Vx, Vy, V eta thetaren jarraipena egitea erabaki genuen. Datu horiek tracker-etik .txt fitxategi batera esportatzen ditugu, eta fitxategi horrek komaz bereizitako datuak CSV formatuan alanbreztatzen ditu.fitxategi hori erabiliko genuke termianletik irekitzeko, visual studio informatikako programa exekutatuz.



Programak gehieneko abiadura angeluarra kalkulatzen du, puntuei (denbora, posizioa, abiadura eta angelua) buruzko informazioa duen CSV fitxategi batetik ateratako datuak erabiliz. Hasteko, erabiltzailearen sarrera balidatzen du komando-lerrotik, eta fitxategiaren izena ematen dela ziurtatzen du. Ondoren, readPoints funtzioa erabiltzen du fitxategia irekitzeko, goiburukoa egiaztatzeko eta errenkada bakoitza irakurtzeko, point_t motako egitura bihurtuz. Prozesu horretan, memoria dinamikoa gordetzen da datuak gordetzeko, eta irakurketan, fitxategiaren formatuan edo memoria esleitzean egindako edozein akats mezu argiekin maneiatzen da. Irakurritako puntuak computeMaximumAngularVelocity funtzioaren gehienezko abiadura angeluarra kalkulatzeko erabiltzen dira. Funtzio horrek ondoz ondoko puntuen arteko angelu-aldaketak (deltaTheta) eta denbora (deltaT) aztertzen ditu. DeltaT hutsala bada, baztertu egiten da puntua kalkulu okerrak saihesteko.

Azkenik, emaitza minutuko biraketetan inprimatzen da (rpm), eta puntuetarako erabilitako memoria dinamikoa freePoints funtzioaren bidez askatzen da. Funtzio horrek bermatzen du ez dagoela erakuslerik zintzilik. Programa sendoa izateko diseinatuta dago, akatsak erabiliz, hala nola gaizki formateatutako fitxategiak, funtsik gabeko datuak eta memoria-falta. Bere egitura modularrari esker, main.cpp, pointreader.cpp, angularvelocitycalculator.cpp eta point.cpp fitxategien artean banatuta dago.



bisual studioan sortu dugun programa artxibotik artxibora azalduko da hemen:

main.cpp

main artxbioak main funkona dauka, programa honetan gainerako funtzioei deitzeko erabiltzen den funtzioa.


1. Goiburukoak barne
#sartu "angularvelocitycalculator.h"
#sartu <stdio.h>
#sartu <csv.h>
#include "angularvelocitycalculator.h": Fitxategi honetan erabilitako funtzioen aitorpenak jasotzen dituen goiburu pertsonalizatua barne hartzen du, computeMaximumAngularVelocity, readPoints, eta freePoints, struct point_t definizioaz gain.
#include: Sarrera/irteerako C liburutegi estandarra barne hartzen du, printf bezalako funtzioetarako beharrezkoa. <stdio.h>
#include: CSV fitxategiak maneiatzeko liburutegi bat barne hartzen du komaz bereizitako balore-fitxategiak prozesatzeko funtzioak. <csv.h>


2. Funtzio nagusiaren adierazpena

int main (int argc, char** argv)
Main funtzioa programaren sarrera-puntua da.
int argc: Komando-lerrotik programara igarotako argumentuen kopurua adierazten du.
char** argv: Komando-lerroko argumentuak biltzen dituen testu-kateen konponketa da. 


3. Argudioak baliozkotzea

if (argc! = 2)
{
printf ("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
printf ("Usage: % s\n", argv [0]); <filename>
return -1;
}
Programa exekutatzean argudio gehigarri zehatz bat eman zen egiaztatzen du, eta kuealak irakurri nahi dugun fitxategiaren izena izan behar du.
Argc ez bada 2:
Programaren helburua azaltzen duen mezua inprimatzen du.
Zuzen nola erabili erakusten du: Usage:./programa. <filename>
- 1 itzultzen du, errore bat adierazten du eta exekuzioa amaitzen du.


4. Aldagaiak adieraztea

struct point_t* points;
Point_t egitura bati erakusle bat adierazten dio; puntu bat adierazten du koordenatuak eta horri lotutako denbora dituen espazio batean.
Erakusle horrek artxibotik irakurritako puntuak gordeko ditu.

int numberOfPoints = readPoints (argv [1], & points);
readPoints (argv [1], & points): Deitu readPoints funtzioari argv [1] atalean zehaztutako fitxategiko datuak irakurtzeko.
argv [1] erabiltzaileak emandako fitxategiaren izena da.
& points erakuslea point erakuslea da, funtzioak memoria esleitzea eta irakurritako puntuak biltegiratzea ahalbidetuko duena.
Funtzio honen emaitza irakurritako puntu kopuru osoa da. Erroreren bat badago, balio negatiboa itzultzen du.


5. Fitxategia irakurtzean erroreak maneiatzea

if (numberOfPoints < 0)
{
printf ("Reading file\n errorea");
return -1;
}
NumberOfPoints 0 baino txikiagoa bada:
Fitxategia irakurtzean errore bat gertatu zela adierazten duen mezu bat inprimatzen du.
- 1 itzultzen du, programaren exekuzioa amaituta.


6. Gehieneko abiadura angeluarraren kalkulua

float maximumAngularVelocity = computeMaximumAngularVelocity (points, numberOfPoints);
Deitu funtzioari konputeMaximumAngularVelocity irakurritako puntuekin eta puntu kopuru osoarekin.
computeMaximumAngularVelocity kalkuluak egiten ditu gehienezko abiadura angeluarra zehazteko, puntuen koordenatuetan eta lotutako denboretan oinarrituta.

printf ("Maximum angular velocity: % f rpm\n", maximumAngularVelocity);
Inprimatu abiadura angeluar maximoaren (maximumAngularVelocity) balio kalkulatua minutuko biraketa kopuruetan (rpm).

freePoints (& points);
Deitu freePoints funtzioari, esleitutako memoria askatzen baitu puntuak biltegiratzeko.
& points erakusle bat point erakuslera pasatzen da, funtzioak memoria behar bezala askatu eta memoria-ihesak saihesteko.

return 0;
0 itzultzen du, programa arrakastaz amaitu zela adieraziz.



hurrengo fitxategia readpoints.cpp da fitxategi honetan, ireki eta .txt fitxategi baten balioak irakurtzen dira, eta haren balioak biltegiratzen dira. Balio horiek konpuatuak izango dira, abiadura angeluar maximoa kalkulatzeko.


pointreader.cpp


1. Makroa definitzea ohartarazpenak ezabatzeko

#define _CRT_SECURE_NO_WARNINGS
Konpiladoreak funtzio "ez-seguruei" buruz (adibidez, fopen edo sscanf konpiladore batzuetan) egiten dituen oharrak ezabatzen ditu. Makro horrek konpiladoreari adierazten dio eragiketa potentzialki ez-seguruak egiteko aukera eman dezala, ohartarazpenik sortu gabe.


2. Beharrezko liburutegiak sartzea

#sartu <stdio.h>
#sartu <stdlib.h>
#sartu <string.h>
#sartu "pointreader.h"
#include: Fitxategien sarrera/irteerarako funtzioak eskaintzen ditu. <stdio.h>
#include: Memoria eta beste utilitate batzuk kudeatzeko funtzioak eskaintzen ditu. <stdlib.h>
#include: Kateak manipulatzeko funtzioak eskaintzen ditu. <string.h>
#include "pointreader.h": ReadPoints bezalako funtzioen deklarazioak eta point_t egitura barne hartzen ditu.


3. Erread_csv_header funtzioa

int read_csv_header (FILE* file) {
char header [256];
if (fgets (header, sizeof (header), file)) {
// Balidatu hemen goiburukoa (adibidez, egiaztatu zutabeen izenak)
return 0;// Baliozkotze arrakastatsua
}
return -1;// Baliozkotzeak huts egin du
}

char header [256]: CSV fitxategiaren goiburuko errenkada gordetzeko bufferra.
fgets (header, sizeof (header),
file): Irakurri lerro bat (255 karaktere arte) fitxategian eta header-ean biltegiratu. NULL itzultzen du huts egiten badu .
Markatzaile Iruzkina: Itzuli 0 goiburuaren irakurketa arrakastatsua bada; -1 bestela


4. Parse_csv_row funtzioa

int parse_csv_row (const char* row, point_t* point) {
int parsed = sscanf (row, " % lf, % lf, % lf, % lf, % lf, % lf, % lf",
& point->t, & point->x, & point->y,
& point->v, & point->vx, & point->vy,
& point->theta);
if (parsed! = 7) {
printf ("Parsing row errorea: % s\n", row);
return -1;// Errorea aztertzean
}
return 0;// Analisi arrakastatsua
}

sscanf (row,...): Row lerroa (kate bat) aztertzen du eta 7 balio ateratzen ditu: t, x, y, v, vx, vy eta theta. Balio horiek point_t egiturari dagozkion eremuetan biltegiratzen dira.
Erroreen egiaztapena: parsed! = 7:7 balioak behar bezala atera diren egiaztatzen du. Bestela, errore bat inprimatu eta -1 itzuliko da. Itzuli 0 analisia arrakastatsua bada.


5. Extract_coordinates funtzioa

void extract_coordinates (const point_t* point, double* x, double* y) {
* x = point->x;
* y = point->y;
}

* x = point->x;* eta = point->y;: x eta eta point_t balioak esleitzen dizkie emandako erakusleei.



6. ReadPoints funtzioa

int readPoints (const char* file, point_t** points) {
FILE* fp = fopen (file, "r");
Helburua: CSV fitxategi batetik datu-puntuak irakurri eta point_t egituren arrai dinamiko batean biltegiratzen ditu.

6.1 Fitxategia ireki

FILE* fp = fopen (file, "r");
if (! fp) {
printf ("Failed to open file: % s\n", file);
return -1;
}
printf ("File opened: % s\n", file);
Ireki CSV fitxategia irakurketa moduan ("r"). Fopen huts egiten badu (adibidez, aurkitu gabeko fitxategia), errore-mezu bat inprimatu eta -1 itzultzen da.

6.2 Goiburukoa balidatu

if (read_csv_header (fp)! = 0) {
fclose (lh);
printf ("Failed to read CSV header\n");
return -1;
}
Deitu read_csv_header-era goiburukoaren errenkada irakurri eta balidatzeko. Balidazioak huts egiten badu, artxiboa itxi eta -1 itzultzen da.

6.3 Gorde memoria puntuetarako

size_t capacity = 350;
* points = (point_t*) malloc (capacity* sizeof (point_t));
if (!* points) {
fclose (lh);
printf ("Memory allocation failed\n");
return -1;
}
printf ("Memory allocated\n");
350 puntuko hasierako edukiera ezartzen du.
Memoria dinamikoki gordetzen du point_t egituren array baterako.
Mallokek huts egiten badu, errore bat inprimatu, fitxategia itxi eta -1 itzultzen da.

6.4 CSVren lerroak irakurtzea eta aztertzea

int count = 0;
char line [256];
while (fgets (line, sizeof (line), fp)) {
if (parse_csv_row (line, & (* points) [count])) = = 0) {
kount++;
if (count > = capacity) {
break;
}
}} {
printf ("Reading line errorea: % s\n", line);
}
}
Irakurri lerroz lerro fitxategia:
fgets (line, sizeof (line), fp): Irakurri fitxategiaren lerro bat buffer linean.
parse_csv_row (line, & (* points) [count]): Lerroa aztertzen du eta datuak point_t egituran biltegiratzen ditu count indizean. Arrakasta badu, gehitu count. Utzi irakurtzeari, esleitutako gaitasuna gainditzen baduzu.
6.5 Erroreak edo azken urratsak maneiatzea

if (count = = 0) {
printf ("Failed to read points from file\n");
}
fclose (lh);
return count;
Punturik irakurri ez bada (count = = 0), errore-mezu bat inprimatu. Artxiboa itxi eta irakurritako puntu kopurua itzultzen da.







agularvelocitycalculator.cpp


1. Oheburuak sartzea

#sartu "angularvelocitycalculator.h"
#sartu <math.h>
#sartu <stdio.h>
#include "angularvelocitycalculator.h": Struct point_t definizioak eta abiadura angeluarraren kalkuluekin lotutako adierazpenak inportatzen ditu.
#include: Funtzio matematikoak inportatzen ditu <math.h>
#include: Sarrera/irteerako funtzioak printf gisa erabiltzeko aukera ematen du. <stdio.h>


2. Funtzioaren adierazpena

float computeMaximumAngularVelocity (const point_t* points, int numberOfPoints)
Parametroak:
const point_t* points: point_t egiturak konpontzeko erakusle konstantea. Egitura bakoitzak gutxienez bi atributu garrantzitsu ditu: theta (posizio angeluarra) eta t (denbora).
int numberOfPoints: Konponketan guztira lortutako puntu kopurua.
Itzuli: Puntu higikorreko balio bat (float), kalkulatutako gehienezko abiadura angeluarra adierazten duena.


3. Puntu gutxiko kasuen erabilera

if (numberOfPoints < 2) {
printf ("Not enough points to calculate angular velocity.\n");
return 0.0f;
}
Konponketan 2 puntu baino gutxiago badaude, ezin da abiadura angeluarra kalkulatu, gutxienez bi puntu behar baitira posizio- eta denbora-aldaketa bat zehazteko:
Errore-mezu bat inprimatzen da.
0.0f itzultzen da, gehienezko abiadura angeluarra ezin dela kalkulatu adieraziz.


4. Gehieneko abiadura angeluarra abiaraztea

float maxAngularVelocity = 0.0f;
Hasi maxAngularVelocity aldagaia 0.0f. Aldagai horrek kalkuluan aurkitutako abiadura angeluar handiena biltegiratuko du.


5. Abiadura angeluarra kalkulatzeko begizta
for (int i = 1; i < numberOfPoints; i++) {
Helburua: Iterar 1. indizetik azkenekora bitarteko puntuen bidez (numberOfPoints - 1).
i indizeak uneko puntua adierazten du, eta aurreko puntuarekin (i - 1) batera erabiltzen da posizio angeluarreko (deltaTheta) eta denborako (deltaT) aldaketa kalkulatzeko.


6. Ondoz ondoko puntuen arteko aldaketen kalkulua

double deltaTheta = points [i] .theta - points [i - 1] .theta;
double deltaT = points [i] .t - points [i - 1] .t;
deltaTheta: Uneko puntuaren (points [i] .theta) eta aurrekoaren (points [i - 1] .theta) arteko posizio angeluarreko aldea.
deltaT: Uneko puntuaren (points [i] .t) eta aurrekoaren (points [i - 1] .t) arteko aldea denboran.


7. Denbora-aldaketa esanguratsua den egiaztatzea
if (fabs (deltaT) > 1e-6) {
Helburua: Ez zatitu balio oso txikiekin edo 0 baliokoekin (horrek kalkulu-erroreak edo baliozkoak ez diren emaitzak eragingo lituzke).
Erabili fabs (deltaT) deltaT-ren balio absolutua lortzeko, eta konparatu 1e-6rekin (oso balio txikia, zero ingurukoa), tolerantzia-atalase gisa.


8. Abiadura angeluarraren kalkulua

float angularVelocity = fabs (deltaTheta/deltaT);
Kalkulatu abiadura angeluarra, aldaketa angeluarraren (deltaTheta) eta denbora-aldaketaren (deltaT) arteko arrazoiaren balio absolutu gisa.
if (angeluarraVelocity > maxAngularVelocity) {
maxAngularVelocity = angularVelocity;
}
Kalkulatutako abiadura angeluarra maxAngularVelocity-n gordetako balioa baino handiagoa bada, azken hori eguneratzen da aurkitutako maximo berria islatzeko.


9. Denbora hutsalen eranskina
else {
printf ("Skipped point % d due to small or zero deltaT.\n", i);
return maxAngularVelocity;
}
Denbora-aldaketa txikiegia edo zero bada, kalkulua ez da baliozkoa puntu horretarako:
Inprimatu mezu bat puntua alde batera utzi dela adieraziz (Skipped point).
Itzuli berehala maxAngularVelocity-ren balio eguneratua begiztarekin jarraitu gabe.


10.Gehienezko abiadura angeluarra itzultzea

return maxAngularVelocity;
Begiztak puntu guztiak prozesatzen dituenean, aurkitutako abiadura angeluarraren baliorik handiena itzultzen du.


points.cpp

Funtzioa hasierako balidazio batekin hasten da, erakuslea erakuslearekin (* points) eta erakuslea ez direla baliogabeak egiaztatzeko. Ondoren, erakuslearekin lotutako memoria askatuko du, "free" (* points) deituz, eta, erakusle zintzilikatzaileen arriskua saihesteko, balio baliogabe bat esleitzen dio erakusleari (* points). Erakuslearen erakuslea nulua delako edo erakuslearen edukia nulua delako askatu beharreko memoriarik ez badago, funtzioak ez du inolako ekintzarik egiten, eta, horrela, portaera segurua eta isila bermatzen da problematikoak ez diren egoeretan.


1. Beharrezko goiburuak sartzea
#sartu "point.h"
#sartu <stdlib.h>
# "point.h" barne:
Inplementazio honetan erabilitako point_t egituraren definizioa barne hartzen du.
Point.h fitxategia funtzio horren deklarazioa duen goiburukoa da (void freePoints (point_t** const points)).
#include: <stdlib.h>
Free () funtzioa malloc, calloc edo antzeko funtzioen bidez esleitutako memoria dinamikoa askatzeko erabil daiteke.


2. Funtzioaren adierazpena

void freePoints (point_t** const points)
Parametroa:
point_t** const points:
Erakusle bat erakusle bat point_t egitura batera.
Horri esker, jatorrizko erakuslea (* points) alda daiteke, memoria askatzeko eta baliogabeko kokaleku batera apuntatzea saihesteko.
Helburua: Dinamikoki esleitutako memoria askatzea point_t konponketa baterako eta erakuslea askapenaren ondoren baliogabe geratzen dela bermatzea.


3. Baliozko erakusleak egiaztatzea

if (points & &* points) {
Azterketa honek bi balidazio egiten ditu:
Points: Erakuslearen erakuslea baliogabea ez dela egiaztatzen du. Pointak baliogabeak badira,* point-era sartzen saiatzeak errorea eragingo luke.
* points: daukan erakuslea (* points) baliogabea ez dela egiaztatzen du. Baliogabea bada, ez dago memoria askatzerik.


4. Esleitutako memoria askatzea

free (* points);
free (* points):
* points = NULL;

Malloc edo calloc funtzioen bidez point_t egiturak konpontzeko aldez aurretik esleitutako memoria askatzen du.
Horrek bermatzen du lotutako memoria-blokea sistema eragilera itzuliko dela, berrerabiltzeko. Memoria askatu ondoren, nullera apuntatzen da, posizio baliogaberik ez emateko.


5. angularvelocitycalculator.h

#pragma once
#include "point.h"
float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints);

Fitxategi honek computeMaximumAngularVelocity funtzioa deklaratzen du, puntu multzo batetik (point_t) gehienezko abiadura angeluarra kalkulatzen duena. #pragma ocne erabiltzen du inklusio anizkoitzak saihesteko, eta point.h barne hartzen du point_t egituraren definizioan sartzeko. Funtzioaren interfaze publikoa definitzen duen goiburuko fitxategia da, eta proiektuko beste fitxategi batzuek erabil dezakete, inplementazioa jaso gabe.

6.Point.h

#pragma once
typedef struct point_t {

	double t;
	double x;
	double y;
	double vx;
	double vy;
	double v;
	double theta; 
}point_t;

// delcaration of the freepoints fucntion
void freePoints (point_t** points);

Fitxategi honek "point_t" egitura definitzen du, eta 2Dko puntu bat irudikatzen du, denbora ("t"), koordenatu ("x", "eta"), abiadura ("vx", "vy", "v" eta "angelu" gisa atributuak dituena. #pragma once "erabiltzen du inklusio anizkoitzak saihesteko eta freePoints" funtzioa deklaratzen du, dinamikoki esleitutako memoria puntu multzo baterako askatzen duena.

7.Pointreader.h

#pragma once
#include "point.h"
int readPoints(const char* file, point_t** points); 


Fitxategi honek "readPoints" funtzioa adierazten du. CSV fitxategi batetik puntuak irakurtzeaz eta "point_t" egituren array batean dinamikoki biltegiratzeaz arduratzen da. #pragma once "erabiltzen du inklusio anizkoitzak saihesteko, eta**, berriz," point.h "** erabiltzen du" point_t "definizioan sartzeko. Goiburuko fitxategi bat da, eta proiektuaren beste zati batzuetan readPoints funtzioa berrerabiltzeko aukera ematen du.


8.Angularvelocitytest.cpp


Goiburukoak
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

#include "CppUnitTest.h": Microsoft Visual Studio-ren unitate-probetarako tresna sartzen du.
using namespace ...: Frameworkaren funtzioak espazio-izenik gabe erabiltzea ahalbidetzen du.
#include "angularvelocitycalculator.h" : computeMaximumAngularVelocity` funtzioaren deklarazioa sartzen du, fitxategi honetan probatu ahal izateko.

Izena ematea eta proba-klasea

namespace UnitTest
{
    TEST_CLASS(AngularVelocityTest)
    {
    public:
        
    };
}

namespace UnitTest: Probak antolatzeko espazio-izena definitzen du.
TEST_CLASS(AngularVelocityTest)`: Abiadura angeluarrarekin lotutako probak biltzen dituen proba-klasea deklaratzen du.

Proba-metodoa: `TestAngularVelocity
TEST_METHOD(TestAngularVelocity)

  1. Hiru puntuko array bat definitzen du, `theta` balioak 0.03-tik 1.0-ra igotzen direlarik.
  2. `computeMaximumAngularVelocity funtzioa deitzen du puntu hauekin.
  3. Emaitza `1.0f` dela egiaztatzen du `Assert::AreEqual` erabiliz.


Proba-metodoa: `TestNoPoints`

TEST_METHOD(TestNoPoints)

Funtzionamendua:
  1. Puntero nulua eta puntu-kopuru zero ematen ditu.
  2. Funtzioa deitzen du eta emaitza `0.0f` dela egiaztatzen du.


 Proba-metodoa: `TestNegativeAngularVelocity`

TEST_METHOD(TestNegativeAngularVelocity)

Funtzionamendua:
  1. `theta` balio negatiboak dituzten puntuekin array bat definitzen du.
  2. Funtzioa deitzen du eta emaitza espero denarekin alderatzen du (`-0.2f`).



Proba-metodoa: `TestVaryingAngularVelocity`
cpp
TEST_METHOD(TestVaryingAngularVelocity)

Helburua: `theta` balio aldakorrak dituzten puntuetan abiadura angeluar maximoa kalkulatzen dela ziurtatzea.
Funtzionamendua:
  1. `theta` balio hazkor eta beherakorrarekin array bat definitzen du.
  2. Funtzioa deitzen du eta emaitza maximoa `0.73f` dela egiaztatzen du.



9.PointreaderUnittest.cpp

Goiburukoak

#include "pointreader.h"
#include "CppUnitTest.h"
#include "pointreader.h": readPoints funtzioaren deklarazioa sartu egiten du.
#include "CppUnitTest.h": Microsoft Visual Studio-ren unitate-probetarako tresna sartu egiten du.

Izena ematea eta proba-klasea
cpp
Copiar
Editar
namespace UnitTest
{
	TEST_CLASS(PointReaderUnitTest)
	{
	public:
		
	};
}
namespace UnitTest: Espazio-izena definitzen du, probak antolatzeko.
TEST_CLASS(PointReaderUnitTest): PointReader funtzioen inguruko probak biltzen dituen klasea deklaratzen du.


Proba-metodoa: TestReadingWorksWithValidInput

TEST_METHOD(TestReadingWorksWithValidInput)
Helburua: Egiaztatu funtzioak zuzenean funtzionatzen duela fitxategi baliozko batekin.
Funtzionamendua: PBLtracker.txt fitxategia irakurtzeko helburuarekin test bat definitzen du.
readPoints funtzioa deitzen da, eta haren emaitza gordetzen da. Logger bidez mezu bat idazten du.
Assert::IsTrue erabiltzen du, numberOfPoints ez bada zero, funtzioak emaitza positiboa itzultzen duela ziurtatzeko.


Proba-metodoa: TestReadingNotWorkingWithInvalidInput

TEST_METHOD(TestReadingNotWorkingWithInvalidInput)
Helburua: Egiaztatu funtzioak errore bat jasotzen duela fitxategi baliogabe batekin.
Funtzionamendua:
invalidpoints.txt fitxategi baliogabearekin probatzea.
readPoints funtzioa deitzen du eta numberOfPoints -1 itzultzea espero du.
Logger bidez mezu bat idazten du.
Assert::AreEqual erabiliz, emaitza -1 dela egiaztatzen du, errorearen seinale gisa.


Proba-metodoa: TestReadingNotWorkingWithInexistentFile
cpp
Copiar
Editar
TEST_METHOD(TestReadingNotWorkingWithInexistentFile)
Helburua: Egiaztatu funtzioak errore bat jasotzen duela fitxategi ez existitzen duen batekin.
Funtzionamendua:
points.txt fitxategia ez existitzen denean probatzea.
readPoints funtzioa deitzen da eta numberOfPoints -2 itzultzea espero da.
Logger bidez mezu bat idazten du.
Assert::AreEqual erabiliz, emaitza -2 dela egiaztatzen du, fitxategia ez dagoela adierazteko.


