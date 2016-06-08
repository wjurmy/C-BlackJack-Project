Oppgave 1: Oppvarming
I oppvarming.cpp finner du tre ulike "beskjeder" som er gjemt i variabler med numeriske typer. Variablene heter hhv. msg1, msg2 og encrypted.

OBS: Variablene er initialisert på C++11-måten (brace initialized), som er den måten du bør venne deg til å bruke konsekvent (Se oppgave 1 fra uke 3-4 om datatyper).

long long msg1{28539401679696455};

int msg2[]{1918986818,1998611822,1684829551, 
            544483182,1701538156,1768453152,8563};

int encrypted[]{1498105673, 1227249735, 1498829639, 
                1196119078, 1314530904, 1197024843, 5853000};
Du skal skrive kode i oppvarming.cpp slik at alle de tre skjulte beskjedene skrives ut. For msg1 og msg2 handler dette bare om å hente ut dataene som enkeltvise bytes. encrypted er imidlertid en hemmelig beskjed fra en av Julius Cæsar (din erkefiende) sine offisérer, så den er i tillegg kryptert. Men, siden du har sett DaVinci-koden vet du at det ikke er vanskelig å knekke Caesars kryptering. Du må imidlertid finne ut selv hvilken offset som er brukt - det kan være et positivt eller negativt tall ;-)

Oppgave 2: Blackjack ♠ ♥ ♦ ♣
Du skal implementere casino-spillet blackjack. Minimumskravet er et spill som virker, med de viktiste reglene (oppgitt under). Objektorientering er ikke et krav, dersom man har lavt eller middels ambisjonsnivå. Det er imidlertid mulig å implementere spillet med en såpass generell objektorientert struktur at mye av koden kan gjenbrukes til flere typer spill (sjakk, poker etc.), med flere typer grensesnitt, og både menneselige spillere og maskinspillere. Har man høyt ambisjonsnivå i kurset kan det være lurt å tenke i denne retningen.

All brukerinteraksjon skal skje via terminal i denne innleveringen, men ta altså høyde for at man kan legge til GUI senere, uten å måtte endre på selve spillogikken.

TIPS: Unicode inneholder fine tegn for "suites", som gjerne kan brukes. Disse støttes ikke over alt, men du kan gjerne bruke dem i oppgaven. De kan da copy-pastes direkte herfra, eller du kan google dem: ♠ ♥ ♦ ♣ ♤ ♡ ♢ ♧

Implementasjon

Alt som tas opp her skal være med, men du bestemmer naturligvis arbeidsrekkefølgen selv.

Lag en kortstokk med 52 kort, med funksjoner for å stokke og å dele. Dette er typisk noe som kan gjenbrukes senere.
Skriv en funksjon som avgjør hvor mange poeng en hånd (feks. en vector av kort) gir. Vurder om dette bør være del av en funksjon, en medlemsfunksjon eller en frittstående funksjon.
Når blackjack startes (med ./blackjack) skjer følgende:
Spilleren starter med et gitt beløp "på konto" og blir bedt om å oppgi innsats, som skal trekkes herfra.
Det deles ut to kort til en vector for dealer, og to kort til en vector for "spiller". Spilleren får se sine egne kort, men ikke dealerens. (men de skal faktisk deles ut bak kulissene)
Det skrives ut hvem som har høyest score, av dealer og spiller.
Programmet tar imot input fra bruker (bruk gjerne cin >> action, der action kan være en string, char, int el. som representerer en handling), og dele ut et kort til i "spillerens" vector hvis "HIT", eller å stoppe hvis "STAND".
Implementér også dealerens handlinger iht. reglene under.
Dette fortsetter frem til brukeren enten har gått "BUST" (over 21) eller stoppet ("STAND").
Det skal nå kåres en vinner av hånden igt. reglene under. Brukeren skal nå få se dealerens hånd.
Brukerens "konto" skal nå oppdateres, og hvis det er penger igjen får man mulighet til å spille igjen. Ellers får man beskjed om at man er blakk.
Lag enkle, men solide løsninger for å håndtere feil som kan oppstå, feks. ugyldig input fra bruker. Exceptions anbefales, men er ikke et absolutt krav siden det enda ikke er dekket i kurset.
Utfordring (valgfri)

Finnes det en vinnende strategi i blackjack? Hva med å "telle kort"? For dere som ønsker en ekstra utfordring; implementér et design som er slik at en menneskelig spiller enkelt kan skiftes ut med en "A.I.", dvs. et program du selv implementerer til å spille mot dealer.

Forsøk først å implementere en veldig "basic" spiller, som bare spiller etter helt enkle prinsipper, á la dealer. Kjør en simulering der det spilles noen tusen spill og se hvor ofte "huset" vinner.
Forsøk så å implementere en spiller som teller kort, og regne ut sannsynligheten for at du skal gå over eller under 21, basert på hva som er gått av kort. Forsøk med hhv. 2, 3 og 4 kortstokker. (Her ser du viktigheten av å implementere kortstokken og delefunksjonen på en mest mulig "naturlig" og intuitiv måte, med støtte for å enkelt kunne slå sammen flere kortstokker). Kjør simulering igjen, og se hvor mye det hjelper.
Dersom du velger å implementere dette, legg inn noen menyvalg for alternativene du har implementert, når man starter ./blackjack
Bruk av git underveis

Som nevnt på forelesning håper vi å kunne bruke git som innleveringsverktøy. Jobb slik:

Synkronisér kursets github-repo til din Linux-VM (Du kan jobbe lokalt også, men Linux-VM'en blir brukt itl retting så det er lurt å jobbe der), feks. med kommandoen  $ git clone https://github.com/hioa-cs/cpp_v2015.git 
Klone ditt eget, private github-repo, med kommando tilsvarende som over (men med din link)
Kopiér mappen "oblig1" inn i ditt github-repo, feks. med kommandoen
 $ cp ./cpp_v2014/oblig1 my_repo  Der my_repo er skiftet ut med mappenavnet til ditt repository. Du får da med oppgaveteksten, og filene der du skal skrive koden.
Implementér dine løsninger i filene oppvarming.cpp og blackjack.cpp. Du kan legge til så mange andre filer du vil, så lenge prosjektet kan bygges med kommandoen make og kjøres med hhv. ./blackjack og ./oppvarming
Du kan nå committe og pushe så mange ganger du vil, frem mot innleveringsfristen forutsatt at ditt repo er privat, og kun du og alfred-bratterud har tilgang (Offentliggjøring eller av innholdet blir betraktet som juks).
Det som ligger i ditt repository når fristen faller blir automatisk klonet ned av oss, og betraktet som din innlevering.
PS: Ikke vær bekymret for å vise "tabber" eller gammel, dårlig kode i historikken - det er bare fint. Det eneste som har noe å si er resultatet til slutt.

Læringsmål

Generelle hovedmål er å vise at man har tilegnet seg

Evne til å implementere et enkelt, fungerende C++ program
Vise at man kan lage et hensiktsmessig design for et enkelt C++ program.
Vise at man kan skrive ryddig, strukturert og oversiktlig kode
Tekniske mål - man skal vise:

Basics: At man mestrer grunnleggende programmeringsteknikker som løkker, kontrollstrukturer og funksjoner (Dette skal man kunne fra før)
I/O: At man mestrer grunnleggende I/O-operasjoner, dvs. kommunisere via terminal.
Minne: At man har forståelse for hvordan de tre ulike typene minne fungerer, og at man bruker dem hensiktsmessig. Det vil si at man rydder opp etter all bruk av dynamisk minne, at man bruker autmatiske variabler fornuftig mtp. størrelse, levetid og skop, og at man er nøye med å initialisere alle variabler.
Parameteroverføring: At man mestrer "pass by reference" og "pass by value" og tar fornuftige beslutninger om når ma benytter hva.
Vector: At man mstrer grunnleggende, standard bruk av vectorer, herunder iterere med iteratorer, samt legge til og evt. fjerne elementer.
Rapport

Det skal foreligge en liten rapport, i .md-format (som dette). Der skal du:

Beskrive blackjack-implementasjonen din, gjerne trekke frem ting du synes var interessant eller vanskelig. Hvis du bruker objektorientering, ta med en figur som viser klassehierarki. (Ingen krav til UML)
Diskutere et alternativt programdesign, hvis du har et, eller idéer til et. Er det noe du ville gjort anderledes? Hvilke fordeler og evt. ulemper ville alternativet gitt?
Rapporten skal hete "rapport.md" og ligge i rotmappen i ditt "repository" (mer info om dette senere)
Tips: For å se hvordan markdown-koden for denne oppgaveteksten er laget, åpne fila og trykk knappen "Raw" ute på github, eller bare åpne den i en tekst-editor.
Du kan lese mer om .md-formatet generelt, her: Daring fireball, Markdown syntax og githubs tilpassede versjon her: Github Flavored Markdown

De viktigste reglene i Blackjack

Blackjack er et kortspill som handler om å få så nært "21" som mulig, uten å gå over. Det fungerer som følger:

Alle billedkort (Konge, dame, knekt) er verdt 10, Ess (A) er verdt 1 eller 11 - det som gir "best" hånd. Andre kort er verdt sitt "tall" (også 10)
Spilleren satser penger. I våre blackjack-regler er det ingen grense.
Spilleren får to kort av "dealer", og dealer får selv to kort. Kun ett av dealers kort er synlige for spilleren.
Hvis spilleren får 21 på første hånd (10 og A), er det "Blackjack". Spiller vinner da 1.5 ganger sin innsats (3:2)
Spilleren må nå velge om hun/han vil ha et kort til (HIT), eller ikke (STAND)
Hvis spilleren står (STAND) på under 21, må dealer avgjøre sin hånd.
Dealer må "HIT" på alt under 17, og "STAND" på 17 og høyere.
Hvis dealer går over 21 (BUST) vinner spilleren 1:1 av sin innsats
Hvis dealer kommer nærmere 21 enn spilleren uten å gå over, vinner dealer spillerens innsats
Dersom dealer og spiller ender på det samme, heter det "Push" - da vinner ingen. Dette gjelder ikke dersom det ble blackjack.
Det finnes to regler til, "DOUBLE" og "SPLIT". Disse kam du vente med. Flere detaljer i rules.md.
