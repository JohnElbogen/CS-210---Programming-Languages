# CS-210
SNHU CS-210 Repository
John Elbogen
12/20/20

**Summarize the project and what problem it was solving.**
This project was designed to calculate balance and interest earned based on investment amounts, monthly deposits, annual interest rates, and total number of years.  Also this project allows users to display their results, and edit their inputs as necessary.

**What did you do particularly well?**
I believe the two strong points of this code include the modularity of each function and how I displayed and update my information.  The display information refreshes to show the menu and results on each input.  This leads to more readable results for the user.

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**
I think I could enhance my code I would add a clock to measure calculation times.  By doing this, I could calculate how long each function was taking to process, and look for more places to add efficient code.  For example I may be more careful and create less instances of storage within memory.

**Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?**
There were challenging aspects of this code.  The main thing was trying to implement try-catch and input checks.  What I found was a way to ignore the entire rest of the line, provided my security checks do not catch.  "numeric_limits<streamsize>::max()" . This method allows me to throw an error and clears their input from the input stream.
  
**What skills from this project will be particularly transferable to other projects and/or course work?**
I think utilizing functions, creating modular - reusable code, and displaying information with clean and organized format will transfer to all code.  In most programs, these are important features to think about, in order to better work with the code, edit the code easier, or even allow others to work with the program.

**How did you make this program maintainable, readable, and adaptable?**
I did this by organizing features and functions.  The organization was based on the order a user would want to access a function.  For example in my menu, the first option is to enter initial amount.  Therefore in my function layout, the first function is the getInitAmt function.  This makes sense when testing, to know where to look for the function.  For readability there were portions written in order to avoid messy code.  The example being, when formatting information.  Rather then write this on one line I wrote it as the following:

```
cout << left
	<< setw(8) << year << "$"
	<< setw(23) << accountBal << "$"
	<< setw(20) << interestEarned << endl;
```
 
This helps seperate and make the code more readable, as the line is not overcrowded.
