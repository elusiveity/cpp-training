I have zero clue what I'm doing. I have been in IT for a decade (started young!) and the best I've done is bloody Visual Basic. So right now I'm sitting here like "web apps are boring and too mainstream; I want to sink my teeth into something more fun". 

Well let me tell you; programming is a cluster fuck to learn yourself. Yeah sure it's easy to learn through a university, but you don't truly learn that gritty, neckbearded, bare bones kind of thing. So that's what I'm doing and to boot; I'm going to be documenting as much as I can even though it'll make this go for a very long time.

First things first; what programming language should I use? Well let me just say that I decided on C before I started writing this. I started looking around but C just stood out; 
It's easy to compile with gcc in bash subsystem for windows or on any linux system
It's the mack daddy of programming languages
Although it's super simple, it should teach me what I need to know

Getting started I'll be doing a lot of boring command line processing. Right now I don't have a specific goal in mind, so I'll be making a lot of this up as I go along. Please note that I'm bound to make a million mistakes in what I'm about to say/write, especially considering that I'm tired as fuck and have the flu, and it's 10:30pm. I'll constantly correct myself as I go.

Also I should note that there is absolutely no structure to this post and I'm writing it as I go. In addition; I will not be explaining any concepts which establish a core understanding of data types and how to manipulate them. We'll be addressing these as we go.


Getting my environment setup
This isn't Python; you need to set yourself up.

The easiest way to "get cracking" is to use a text editor with a simple compiler. I'll be using bash because Linux is the best. I use Bash for Windows, so...

Get compiler: apt install gcc
Get text editor: apt install vim-enhanced

'Writing a Hello World'
Shout out to this guy: https://www.youtube.com/watch?v=oW9KhE7Q5ss
Your video pissed me off but whatever.. you got me started.

Let me save you eight minutes..

Explanation 1: You will write your code in a text editor, then you'll compile it with your compiler. 
Explanation 2: You will write your code in vim, then you'll compile it with gcc.

I have created a folder called Projects under my home directory. Directory creation is handled with mkdir, so if you check your terminal it should say something like "/mnt/c/Users/<user>/", if not you can call that directory by doing "cd /mnt/c/Users/<your user>". Then created Projects by doing `mkdir Projects`
Inside here I have created a folder called "cpp-training" then "hello-world". `mkdir -p Projects/cpp-training/hello-world`. then cd Projects/cpp-trianing/hello-world

You'll want to start writing your code, so let's create a file called "hello.c". The .c is important for gcc because it'll tell the compiler that this is a C program, not a C++. VIM allows you to open a file that doesn't exist, then create it when you save so you can simple do `vim hello.c` and the text edtior will open.


I understand that the interface can be daunting, so here's all you need to know:
VIM opens up in "command mode". You can drop into "editting mode" by pressing "i" whilst in command mode. When you do, you'll see -- INSERT -- appear at the bottom left.
When you're finishing editing your file, simple press ESC (escape key) to go back to command mode. 
To save a file, type :w and you'll see it appear down the bottom. Press enter to run the command.
To exit vim, you can use :q however this won't work if oyu haven't saved your changes. If you want to save and exit, you can use :wq but if oyu want to exit without saving, you would use :q!

So now that you have vim open, enter "editing mode" and start typing in the following: 

```
#include <stdio.h>
 
int main (void)
{
     printf("%s", "hello world");
     return 0;
}
```

Let me explain what we've just done line-by-line:
`#include` tells the compiler what headers to include when compiling this application. Typically we do not like re-inventing the wheel because it would never always be round, however when we interface with the operating system we need often need a standard method of doing so. Your code will interface with the operating system, so it's important to include headers which permit you doing so. In this case, `<stdio.h>` translates to "standard input/output header", with "stdio" = "standard input/output" and ".h" indicating a header file. Being wrapped in whatever < and > is called means it's calling headers that are built-in to the compiler. 
So we're "including the standard input and output headers", which will allow us to enter text into our application via the command line and print out a response.

int main (void) is where it get's a little tricky. In programming, you always have the first thing to execute and we call this "main", because it's the "main class". If you think of a procedural language like PHP and you had `<?php echo "asd"; ?>` or in Python you had `print "some text"` at the top of your code, the first thing that application would do is print "asd" and "some text". Programs written in C can have multiple classes defined which process data differently, so it's important to declare the 'main class' so that the compiler know's what to run first.

The contents of the main class are contained within curly brackets: the definitiion of the main class should be immediately succeeded by an opening curly bracket ({), with a closing curly bracket (}) concluding the content of the main class.

printf is a function introduced by stdio.h. It allows us to "print" something to the command line and I have yet to learn what the fuck the F means.

Return is a tricky one to explain... so I'll do it when I have a better explanation. It's super important though and I don't recommend getting lazy by not using it.

Compile your Hello World

To compile your hello world, simply run 'gcc hello.c' from the command line. This will create an executable "a.out" file, which can be run by entering "./a.out" into the command line.

---


Now that you have a fully functioning program; what can you do with this?

When I was stuck thinking what I could use Python for, I decided to start with something simple; a dice game. Allow the user to enter their guess, randomly select an integer between 0 and 7 (so 1, 2, 3, 4, 5 and 6), compare the result, repeat the process until the user has had enough.

This is where things get tricky because my understanding of C is limited, however using the dreaded "pseudocode", our logic would be something like this:

```
while (0)
{
     Request input, put into variable "usrInput"
     Randomly generate a number between >0 && <7, put into variable "roll"
     if userInput == "q"
     {
          break;
     } else {
          Randomly generate a number between >0 && <7, put into variable "roll"
          if userInput == roll
          {
               printf("you win!");
          } else {
               printf(Your lose!");
          }
     }
}
```

I just learned what the "F" means: it means "formatted". This means you can do `printf("You guessed %s and rolled %s, you %s", userInput, roll, rollResult)`, which will print "You guessed 4 and rolled 3, you lose" when userInput = 4, roll = 3 and rollResult = "lose".

Anyway, let's translate this into a C application. First thing I did was create a new folder called "dice-roll" under "cpp-training", then `vim dice-roll.c`. Before you read on, I would recommend trying to do this yourself without my help however if you're not able to then read on. I'm doing most of this without looking up specific commands and then I'll edit what I've written so that it actually works.

So to get started I am going to simplify the input/output behaviour of C so that you can wrap your head around it. I already know this basic, so it was easy for me, but being new to a language it might seem weird.

```
#include <stdio.h>

int main (void)
{
     int userInput;
     scanf("%d", &userInput);
     printf("You entered %d", userInput);
     return 0;
}
```

Running this will give you the following:




Let me explain the newly introduced changes:
`int userInput` will create the userInput variable ahead of time. In C this is called a pointer and I have used a short hand version of using them in this script, thanks to wikibooks, because the real way is an absolute mind fuck. I should also explain that we're using integers because right now, at this very moment, it's EXTREMELY easy to handle integers unlike strings...
`scanf` tells the program to scan for user input. We format it as "%d", which for some reason means the program should expect an integer. &userInput will place the integer into the pointer we declared on the line above.
`printf` operates as I just explained, however %d here will tell C that it's printing an integer, which is apparently very important for some very complicated reason.

You can see that when I input a number, the program works as expected however when I enter characters like "a" and "z", it does not work. This is because we have told our program to use integers and not strings, which are two very different things.

The next thing to do would be to do some calculations... 

---

'Writing a simple addition calculator'

I'm bored now, so let's take this up a notch. We're going to enter into a continuous loop until we break it. We're venturing into dangerous territory, considering I don't understand how C stores strings in the memory.

```
#include <stdio.h>

int main (void)
{
        int breaknote;
        int userInput;
        int tally;

        breaknote = 1;

        /* Start with the first number */
        printf("  ");
        scanf("%d", &tally);

        while (breaknote)
        {
                /* Keep adding to the first number */
                /* 0 breaks our of the loop */
                printf("+ ");
                scanf("%d", &userInput);
                if ( userInput == 0)
                {
                        breaknote = 0;
                } else {
                        tally = tally + userInput;
                }
        }
        printf("----\n%d", tally);
}
```


This was surprisingly easier than expected.

First, we created three variables: breaknote, userInput and tally. Breaknote will keep our loop going so long as it's greater than 0, userInput will be our users input and we'll keep calculating tally based on what the user puts in.
We set breaknotes value to 1, so that the 'while' loop will continue indefinitely.
We scanf for our first number to work with, then enter into an indefinite loop using "while". What we're saying here is a shorthand way of saying "while ( breaknote > 0 )", do the following. 
The while block will continue through that process until you break out of it; in this case, setting breaknote to zero.
The while block will continually prompt the user for a number, add it to the tally, then repeat the process until the user enters '0'. When the user enters '0', it will break free.
Anything between /* and */ is considered a comment and will not be processed by the compiler. It's the best way to 'document' your code so that you understand what the hell you're doing when you revisit it.

---

'A dice game'

My laptop battery is at 10%; so let's quickly do a dice game!

create a new file; real-dice-game.c

Again, I'm just going to guess the code then fix it up. You'll see the end result, but i recommend attempting to guess yourself at this point. What we want to do is continuously request a number, generate a random number, then compare the two.


Not bad for the third attempt. First two errors were formatting errors. Only two things i looked up; how do to an elseif statement, and how to generate a random number. 

And here we go: 


What you'll notice is one single constraint here: you can never guess zero. That's because I'm using a shitty way of randomly generating a number, which will only be random once every second, and will guess from 0 to 5. It's also not very random, with a high probability to generate the same number more than once in a row: 


Anyway, here's the code:
```
#include <stdio.h>
#include <time.h>

int main (void)
{
        int breaknote = 1;
        int guess;
        srand(time(NULL));

        while (breaknote)
        {
                printf("Enter your guess: ");
                scanf("%d", &guess);
                int r = rand() % 6;
                if ( guess == 0 )
                {
                        breaknote = 0;
                } else if ( guess == r ) {
                        printf("We rolled %d: you win!", r);
                } else {
                        printf("We rolled %d: you lose!", r);
                }
        }

        return 0;
}
```

So first we include the stdio.h header, but also the time.h header (again, another in-built header in gcc). The time header will allow us to utilize the clock to generate a random number, because computers can only generate "random" numbers via a complex formula and for simple uses, we utilize the time.
We then declare our main class and create our breaknote and guess variables. srand is something we apparently have to call in order for the rand() function to work.
We then jump straight into the repeated loop, which will ask us for our guess, generate a random number up under 6, check if our guess is "0" and break out of the loop if it is. If it isn't zero, it will compare our guess against the random number; if you guessed correctly, you win but if not, you lose. The loop then repeats until you kill the application or enter 0.

It's also useful to note that "=" sets the variable, so "int asd = 1" will set the variable "asd" to value "1", where-as "==" is a comparison, so "asd == dsa" would me "asd is equal to dsa?".
We also have "else" here. I never explained this. "else" means "if the last thing isnt true, then this is what you do". "else if" means "If the last thing isnt true, then check if this is true".

If we had 

```
int asd = 1;
if ( asd > 1 )
{
     printf("Too rich for my blood");
} else if ( asd < 1 ) {
     printf("You crafty bastard");
} else {
     printf("It has to be 1, because it's not greater than 1 and it's not less than 1, then it's 1.");
}
```

Then the script would guess correctly, because asd was not greater (>) than 1, nor was it less (<) than 1.

You can find out more about "operands" via Google.

---

That's it for one night. It's now midnight, I've had my fun and technically, I've picked up C. Kudos to you if you followed along! You'll be contributing to the Linux project in no time!

Feel free to email me at jb@linux.com if you need help.
