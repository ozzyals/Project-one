# 🚀 Welcome to Project & Portfolio!
<br>

# Project & Portfolio 1

### Student First & Last Name

Hello my name is David Alsworth. I am a student from New York. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Update: Week one Progress. Week one was busy I completed all the setup for this project by creating a Git Repo and cloned the repo to my local storage. I planned what I wanted my project to be and created the core classes for the main systems in my project. I created a working menu and got the player class working with a sanity stat. I got the rooms class working building the individual rooms with names and descriptions and items and the start of an item class. I got the asylum class working intigrating the player and the rooms into a map that the player can move through. I created issues and checked them off as they were completed and pushed updates to git at important milestones. I think for the first week progress was great.

The bigest challenge i had this week was deciding what I was going to make. The freedom was nice, but I was overloaded with options. I found it to be somewhat dificult to come up with a project that fit the required scope and keep it managable. There are so many features and things I want to add but I know I need to get the core of the program running and polished before I can add extra features and art. I also encountered a build error that took a bit to track down, essentially I had temporaraly declared a static variable and then later when I went to implement the feature, that would have defined that variable, I forgot to remove the temporary definition. It wasnt hard to fix but i didnt see it right away. 

I think I really made progress on working throughout the week, as opposed to cramming at the end of the week. Time management is going to be an ongoing issue that I activly need to work on, but this week I think I nailed it.

My next step is to add Items to the rooms. The next point of focus will be planning win/loss conditions and figuring out the ""game" portion of the game. I dont want to get too focused on the story details and art until later in the project but I need to at least plan enough to figure out event triggers.
### Week 2

⚙️ Overview – What did you work on this past week?

This week I really focused on getting everything the game has to have working functioning. I got items working early on which mostly had my prototype working. I felt the game needed a graphical map so the player could visualize where they were and where they had been. The game also needed a way to win or lose. Additionally the narrative adventure needed narrative so i spent a good amount of time updating some of the more important item descriptions and the ending messages. 

🌵 Challenges – What obstacles did you encounter, and how are you addressing them?

The biggest issue this week was time. I missed out on being able to work on it Thursday and I don't usually get much done on Mondays. I got some big stuff done early in the week and I did a ton of work on the game Friday. I started with the stuff that really had to be done to be a complete prototype first and then worked on the stuff that was more interesting last. That way if I ran out of time I would have still been in an ok position. 

🏆 Accomplishments – What is something you learned, improved, or "leveled up" on this week?

I think I leveled up my debugging skills this week. I hit a few errors this week but nothing got me stuck the way it did in earlier courses.

🔮 Next Steps – What do you plan to prioritize before Week 3?

Going into week three I want to make the game better to look at. ASCII art Different color txt, clear screen, are all featured that desperately need to be added but i couldn't justify spending time on until the game was in a playable state

### Week 3

⚙️ Overview – This week I focused on readability. I added some colors red, green, and yellow to certain text to highlight important information to the player. I also changed the order that information prints so that the map and room descriptions are first and the choice generated info is right before the menu. 
🛠️ Improvements – clear screen was added this week, all other improvements were just layout and highlight colors. 
🌵 Challenges – Changing the print order was difficult because clear screen was implemented inside of my functions. Since clear screen would wipe anything before it, and i wanted print map and look around to print before it. I had to move print map and look around into my functions.  Which meant I had to update all my functions parameters, call sites and forward declarations.  Along the way My logic broke several times and I had to fix sooo many bugs. 
💬 Feedback – I got two good pieces of advice this week. One was to remember to take a break and the other was that i could split my longer text into different screens and prompt the user to press a button to continue reading. I think this will be my fix next week to try and get everything displayed without scrolling the screen and usable on a variety of screen sizes.
🔮 Next Steps – For week 4 I want to get everything displaying without having to scroll the screen. I also have a couple functions I want to move outside of main and i still need to properly comment my code.

### Week 4

⚙️ Overview – This past week I worked on adding a loop that lets the player chose if they want to play again or end the game when they reach an end game condition. I felt this made more sense with my project than adding a save function. Additionally I did a lot of polishing.

🛠️ Project Wrap-Up – This past week I polished everything. I recolored All the text and expanded on the room descriptions. I moved all the functions declared in Main to a new class GameFunctions. Additionally, I fixed a bug that was causing the fog of war on my map to be behind one move.

🌵 Challenges – The biggest challenge this week was the tediousness of the work I was doing. Nothing was super complicated but all the polish required going over Literally every line to make small changes. 

📚 Biggest Takeaway – The Biggest thing I got from this class was confidence. I know now that if I plan, work one piece at a time, and put in regular work, I can totally make a program from scratch. There were lots of challenges this month but nothing that couldn't be figured out with the many resources at my disposal.
 
🔮 Future Development – I would significantly expand the layout, the story, and the branching narrative. I would like to have incorporated ASCII art but In a way that wouldn't clutter the UI.

