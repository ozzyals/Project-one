# Docs.

In week 3 I added clear screen, added color to important text and changed the print layout of information. I had to refactor my code to include the print map and look around into most of my other functions to allow for the layout change. 


⚙️ Overview – This week I focused on readability. I added some colors red, green, and yellow to certain text to highlight important information to the player. I also changed the order that information prints so that the map and room descriptions are first and the choice generated info is right before the menu. 

🛠️ Improvements – clear screen was added this week, all other improvements were just layout and highlight colors. 

🌵 Challenges – Changing the print order was difficult because clear screen was implemented inside of my functions. Since clear screen would wipe anything before it, and i wanted print map and look around to print before it. I had to move print map and look around into my functions.  Which meant I had to update all my functions parameters, call sites and forward declarations.  Along the way My logic broke several times and I had to fix sooo many bugs. 

💬 Feedback – I got two good pieces of advice this week. One was to remember to take a break and the other was that i could split my longer text into different screens and prompt the user to press a button to continue reading. I think this will be my fix next week to try and get everything displayed without scrolling the screen and usable on a variety of screen sizes.

🔮 Next Steps – For week 4 I want to get everything displaying without having to scroll the screen. I also have a couple functions I want to move outside of main and i still need to properly comment my code.







