<h1> Spell Checker </h1>
Implements a spell checker as a trie data structure and tells you the number of words misspelled,
number of words in the dictionary, words in the text and the time to call all the functions.

Taken from HarvardX's CS50: Introduction to Computer Science Problem Set 5. The Makefile and speller.c files were
implemented by CS50's staff while I implemented dictionary.c and made changes to dictionary.h



<h2> How to Use </h2>
Usage is as follows:

    ./speller [Dictionary] [text]
    
The dictionary command-line argument is optional, as the default is in dictionaries/large.
The list of texts available are in texts/ with the results of each program in keys/.

The dictionary is assumed to have only lowercase letters and apostrophes.


Examples:
   
      ./speller texts/wordsworth.txt

      MISSPELLED WORDS


      WORDS MISSPELLED:     0
      WORDS IN DICTIONARY:  143091
      WORDS IN TEXT:        158
      TIME IN load:         0.14
      TIME IN check:        0.00
      TIME IN size:         0.00
      TIME IN unload:       0.12
      TIME IN TOTAL:        0.26
  
  
  
  
  
      ./speller texts/constitution.txt

      MISSPELLED WORDS

      USConstitution
      http
      usconstitution
      const
      html
      tempore
      Impeachments
      Nays
      Nays
      repassed
      Piracies
      Felonies
      attainted
      Langdon
      Gilman
      Brearley
      Mifflin
      Clymer
      Fitzsimons
      Jared
      Gouvernour
      McHenry
      Jenifer
      Blount
      Spaight
      Cotesworth
      tempore
      tempore
      tempore
      tempore

      WORDS MISSPELLED:     30
      WORDS IN DICTIONARY:  143091
      WORDS IN TEXT:        7573
      TIME IN load:         0.13
      TIME IN check:        0.00
      TIME IN size:         0.00
      TIME IN unload:       0.11
      TIME IN TOTAL:        0.24
