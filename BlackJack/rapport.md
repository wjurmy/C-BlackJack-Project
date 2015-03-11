Dette er en rapport som beskriver BlackJack programmet.

Programmer er laget slik:

- Strukt for enkelt kort
Et strukt inneholder informasjonen om et enkelt kort. 
Det vil si farge, nummer og hvilken verdi kortet har i blackjack.
Konge, knekt osv har jo alle verdien 10, men vi lagrer også om kortet 
faktisk er en konge eller knekt osv.

- Liste av kort
Så defineres en liste av 52 kort, som er de 52 kortene i en vanlig kortstokk.

- Shuffle Cards
En funksjon som heter shuffle cards tar inn kortstokken og 
stokker om på den. En ny kortstokk defineres inne i funksjonen 
og det plukkes ut et og et tilfeldig kort fra den gamle. Den 
nye kortstokken returneres.

- Initialiserer BlackJack
Resten av koden foregår i funksjonen Play_BlackJack. Her initialiseres først
et pengebeløp som vi starter med, 10 000. Dette er banken til spilleren.
Spillet er en-player. Vi lager to lister som skal holde hvilke kort som 
er delt ut. En liste holder kontroll på kortene til spilleren, en liste 
holder kontroll på kortene til dealeren.

- Initial dealing
Spilleren gir en bet som må være lavere eller lik sin balanse i banken. 
Så deles det ut to kort. To kort går til dealeren hvorav et vises og er 
synlig for spilleren. To kort går til spilleren som begge selvfølgelig 
er synlig. 

- Hit og stand
Spilleren får oppgitt sin verdi, dvs om han har 20, 15 eller hva når 
kortene legges sammen. Hvis han har et ess oppgies esset som 11 helt til 
summen eventuelt overgår 21. Da reduseres esset til 1. Spilleren kan velge
hit eller stand og får da et nytt kort. 

- Versus the Dealer
Når spilleren enten går over 21 eller på en annen måte sier seg ferdig 
er det dealeren sin tur. Dealeren kjører vanlig blackjack regler og 
henter nye kort helt til han kommer over 17. Så bestemmes det hvem som 
har vunnet og spilleren får 2:1 odds på hvert spill. Dvs hvis han vinner 
får han igjen dobbelt opp. 

- Sjekk balanse
Etter hvert spill sjekkes det om balansen er i 0, hvis den er det 
kanseleres spillet.

- Sjekk om replay
Spilleren gir så input ja eller nei (på engelsk) om han ønsker å spille mer.
Hvis ja gjentas dette til spilleren er blakk eller velger å avslutte.