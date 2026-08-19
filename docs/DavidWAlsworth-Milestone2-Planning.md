> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**FullShell Asylum**
→   
  
**What does your program currently do? (1–3 sentences)**   
→

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   The main menu works. the player can move around and interact with items. There are win and loss conditions.
  
**What is NOT working or incomplete?**   
→   The game needs polishing and artwork. the players sanity stat can go above 100 i might change that in a future update. I need to impliment clear screen and alternate text colors to make the game easier to follow and more visualy appealing.
  
**What feels confusing or messy in your code?**   
→ The menu options arent my favorite. I have a bit too much code in main. Where the game handles items with the sanity draining aspect is a little wonky after making some changes.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week. 

1. controls
2. art
3. clear screen

  
### Feature 1  
**Name:**   
→   controls
  
**What does this feature do?**   
→   its how the user makes choices and interacts with the game.
  
**Why is this feature important?**   
→   It is what tells the player what they can do and dictates how they can interact with the game.
  
---
### Feature 2  
**Name:**   
→   Art
  
**What does this feature do?**   
→   this feature adds ASCII art to the game.
  
**Why is this feature important?**   
→   I Think art will make the game feel more immersive.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   clear screen
  
**What does this feature do?**   
→   this clears the screen after the player makes a menu selection.
  
**Why is this feature important?**   
→   It cleans up the information presented to the player and makes it easier to follow what is going on.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   yes I will probably make an ASCII or Art class. 
  
**Will you modify any existing classes? How?**   
→   no i think the menu and clear screen will all be done in main. Ill probably modify text in the Asylum class though as i continu to polish the narative.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   probably vectors for storing ASCII art. 
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   player sees a start menu and is prompted to press enter
2. User chooses →   which direction to move or what to interact with or to check ststs or inventory
3. Program responds →   by moving the player interacting with an object in the room or displaying players sanity or item list
4. Loop/next step →   the player makes another choice until a win or lose condition is met
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   I dont like the player having to enter a prompt to move and then a prompt for direction. I want to simplify it to have the player just chose a direction if they want to move.
  
- Better error handling:   
→   so far my error handling is pretty good I could add more detail in my invalid option message.
  
- Improved menu/navigation:   
→   I am going to move the look around and build map feature to trigger automaticaly when the player moves
  

---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   Time managment I am going to be down a day of programing.
  
**What is your plan if you get stuck?**   
→   stay up stupid late and drink energy drinks and be really frustrated until i achieve whatever im working on.
  

---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   naration
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   TaLKING TO MY MORE CREATIVE FRIENDS AND GETTING IDEAS AS WELL AS BRAINSTORMING WITH AN LLM
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ Visual map]   
- [win/loss]   
- [items and interact ]   
- [ improve narative]   
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ yes] Do I know what I’m building this week?   
- [ yes] Do I know where to start?   
- [ yes] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.