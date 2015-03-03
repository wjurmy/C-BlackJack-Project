# Oblig 1

### Resultat: 
Ikke godkjent / Lever på nytt


### Checklist:
* [] Begge programmen bygger med `make`.
* [] Begge programmen starter og kjører under Linux.
* [] **oppvarming** gir riktig output.
* [] **blackjack** har det viktigeste funksjonaliteten.
	* [] En spiller har et saldo og kan satse et beløp.
	* [] En spiller har valgen "HIT" og "STAND".
	* [] En spiller kan ikke fortsette når den har gått tom for penger.
	* [] Dealerns handlinger virker riktige.
	* [] Spillet følger reglene til BlackJack.
* [] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [] Ingen minnelekasjer funnet med `valgrind`.
* [] Repo innholder `RAPPORT.md`.



### Tilbakemelding:

Mangler Makefile og `RAPPORT.md`. 

`oppvarming` melding 3 (decrypted) gir ikke riktig resultat.

BlackJack starter men avslutter direkt:

	./blackjack
	Shuffling cards.
	Lets play blackjack!
	Hello World
	// end of program
