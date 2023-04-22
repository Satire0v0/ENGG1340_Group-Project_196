#include "room.h"

int attractevilspirit = 0; 
int hammer = 0;
int nightvision = 0;
int protectivetalisman = 0;
int gun = 0;

// room2 中的其他天赋；
Player train1(Player player){
    string storytrain1a = "Now it is 22:15 in a snowy and shivering night, you stand on a railway platform, waiting for the last train of the day to go home after a big day. Your home is 100 miles away from where you work. Suddenly, a gust of wind comes and you hear the sound of the train. At the same time, the station broadcasting says the train will arrive after 15 minutes. “It is quite strange” you whisper quietly.";
    string storytrain1b = "What is your choice?   A.Get in  B. Wait for the next train";
    cout << storytrain1a <<endl;
    cout << storytrain1b <<endl;
    string choice;
    cin >> choice;
    if(choice == "A"){
        return train2(player);
    }
    else{
        cout << "“What’s going on?” you begin shouting. An invisible, strange force push you into the train harshly." << endl;
        return train2(player);
    }
    return player;
}
Player train2(Player player){
    string storytrain2a = "The door close as soon as you enter the train.";
    string storytrain2b = "After a while, an old granny appear in your eyesight. You saw she is close to you, walk in a very difficult way.";
    string storytrain2c = "What is your choice  A.Give your seat to her  B. pretend as you haven’t see her";
    cout << storytrain2a << endl;
    cout << storytrain2b << endl;
    cout << storytrain2c << endl;
    string choice;
    cin >> choice;
    if(choice == "A"){
        string grannysaid1 = "“Dear, do you believe in fortune? Do you believe there are too many things scientists are unable to prove?” said the granny.";
        cout << grannysaid1 << endl;
        string grannysaid2 = "What is your choice? A.Answer “Yes”  B.Answer “NO” C.Begin fear to the granny and go away";
        cout << grannysaid2 << endl;
        string choice2a;
        cin >> choice2a;
        if(choice2a == "A" || choice2a == "B"){
            string grannysaid3 = "“Trust me then you will definitely be fine. Remember, take every chance you have” said the granny. Then she take 2 protective talisman and tell you “This is for you.”";
            cout << grannysaid3 << endl;
            string train22 = "What is your choice? A: take the 2 protective talisman   B. refuse and go away";
            protectivetalisman = 1;
            cout << train22 << endl;
            string choice2b;
            cin >> choice2b;
            if(choice2b == "A"){
                return train3(player);
                protectivetalisman = 1;
            }
            else{
                string train23 = "After a while, you hear the sound of dithering coins. A beggar is walking around the train.";
                string option2c = "What is your option?  A.Feel fear and walk away   B. Report to the station police there is a beggar  C. five him some money ";
                cout << train23 << endl;
                cout << option2c << endl;
                string choice2c;
                cin >> choice2c;
                if(choice2c == "A" || choice2c == "B"){
                    if(protectivetalisman == 0){
                        protectivetalisman = 1;
                        return train3(player);
                    }
                    string beggarsaid = "'Thank you very much and you are so kind!' said the beggar. Then he give you a piece of paper in return, you keep the paper and put it in the pocket";
                    cout << beggarsaid << endl;
                }
                else{
                    return train3(player);
                }
            }
        }       
    }
}
Player train3(Player player){
    string storytrain3a = "Suddenly, you believe the feel in your mind: the train is weird because of the things happen and the people you meet on the train, it just like the horror movies you watched before. Then, you begin to suffer in extreme fear and worrying whether can go back home safely, lie in your bed tonight.";
    string storytrain3b = "However, the things happen minutes ago are not the last and are not the worst. Soon you saw the railway platform but the train does not seems to stop.";
    string option3a = "What is your option?   A: break the window and escape  B: Stay in the train  C:Discuss the situation with people nearby";
    if(protectivetalisman == 1){
        cout << "D: Go to the driver’s cab to ask the driver what’s going on" << endl; 
    }
    cout << storytrain3a << endl;
    cout << storytrain3b << endl;
    cout << option3a << endl;
    string choice3a;
    cin >> choice3a;
    if(choice3a == "A"){
        cout << "However, the train travels too fast, you got seriously injured after escape" << endl;
        // player.update(-1*(player.get_HP()/2), 0, 0); // halve the life
        return train4(player);
    }
    else if(choice3a == "B"){
        return train4(player);
    }
    else if(choice3a == "C"){
        cout << "You begin talking with other passengers and know more about the strange things happen tonight. A few minutes later, one of the passengers give you necklace and according to him, the necklace can bring luck to its hosts. You take it and use it as a weapon against fear.'" << endl;
        attractevilspirit = 1;
        return train4(player);
    }
    else{
        cout << "'Don't go!', the passenger shout at you. Then he tells you the reasons for those weird things happen: " << endl;
        cout << "From the other passengers, you know there is a strange virus spread accross the city. The people who are infected will lose awareness and become another creature --- zombie" << endl;
        return train4(player);
    }
}
Player train4(Player player){
    string storytrain4a = "After a very long time, the train stop at a strange place, there is a disgusting smell in the air and there is dust everywhere, just like no one had been here for many years.";
    string option4a = "What option you will choose?   A.Get off the car with nothing  B. Get off the car with the a fire hammer  C. stay in the train";
    cout << storytrain4a << endl;
    cout << option4a << endl;
    string choice4a;
    cin >> choice4a;
    if(choice4a == "A" || choice4a == "B"){
        return train5(player);
    }
    else if(choice4a == "B"){
        int hammer = 1; // add talent
        return train2(player);
    }
    else{
        // player.update(-1*(player.get_HP(),0,0)); // die
        return player;
        cout << "You are killed by the zombie driver - the driver of the train" << endl;
    }
}
Player train5(Player player){
    int input1;
    int input2;
    int input3;
    int input4;
    int input5;
    string storytrain5a = "The luckiest thing is that you survive from the the crisis and do not need emergency medical treatment.";
    cout << storytrain5a << endl;
    cout << "Press '1' to know more. " << endl;
    string input5a;
    cin >> input5a;
    if(input5a == "1"){
        string storytrain5b = " However, you are the only survive of the incident, other passengers are all killed by the zombies, right now their bodies are scattered everywhere in the train.";
        cout << storytrain5b << endl;
        cout << "Press '2' to know more. " << endl;
        string input5b;
        cin >> input5b;
            if(input5b == "2"){
            string storytrain5c = "Now, you step out the train to the underground castle outside in order to seek chance to survive. Even though the situation makes you feel heart breaking, fear and downcast, you still want to leave this terrible place, go back to normal life.";
            cout << storytrain5c << endl;
            cout << "Press '3' to know more. " << endl;
            string input5c;
            cin >> input5c;
                if(input5c == "3"){
                string storytrain5d = "“I have to let everyone know here and protect others away from here!” whisper by you while walking forward to look for way to freedom. In the darkness,";
                cout << storytrain5d << endl;
                cout << "Press '4' to know more. " << endl;
                string input5d;
                cin >> input5d;
                    if(input5d == "4"){
                    string storytrain5e = "you hear some noise which you haven’t heard before but you are sure that this cannot be pronounced by human being, associated with news about zombies appear in the city, you recognized they are zombies. At the same time, you see a secret door on the wall on your left.";
                    cout << storytrain5e << endl;
                    string option5a = "What is your choice?  A: Use your body to smash the door  B: Continue running forward";
                    cout << option5a << endl;
                        if(hammer == 1){
                            cout << "C: Use the fire hammer to smash the door " << endl;
                        }
                            string choice5a;
                            cin >> choice5a;
                            if(choice5a == "A"){

                                return room1(player);
                                // player.update_HP(-0.1*(player.get_HP())); // lose 10% life
                            }
                            else if(choice5a == "B"){
                                // player.update_HP(-1*(player.get_HP())); // die
                                cout << "You are using all the energy left inside your body and ran as quickly as possible. In your memory, you had never ran so fast. Unfortunately, the zombies have no feelings so they are much faster than you, you hear the voice of zombies from far to near, from drained to exciting. You still cannot face the truth which you may not survive, you tried to ran faster and faster. Suddenly, you lose your balance, the zombies pounced on your, you lose your feeling and mind gradually in pain." << endl;
                                return player;
                            }
                            else{
                                return room1(player);
                            }
                }
            }
        }
    }
}
Player room1(Player player){
    // readme
    return room2(player);
}
Player room2(Player player){
    string storyroom2a = "In this room, there is a treasure box, you can take everything you need but the maximum number of equips you can take is 3, use your chance wisely”";
    string optionroom2a = "A.Medicine1 B.Medicine2 C.Medicine3 D.armour1 E.armour2 F.armour3 G.torch H.handgun I.Rifle J:night vision goggles";
    cout << storyroom2a << endl;
    cout << optionroom2a << endl;
    string choiceroom2a1;
    cin >> choiceroom2a1;
    string choiceroom2a2;
    cin >> choiceroom2a2;
    string choiceroom2a3;
    cin >> choiceroom2a3;
    if(choiceroom2a1 == "J" || choiceroom2a2 == "J" || choiceroom2a3 == "J"){
        nightvision = 1;
        player.talent.vision = true;
    }
    if(choiceroom2a1 == "H" || choiceroom2a2 == "H" || choiceroom2a3 == "H" || choiceroom2a1 == "I" || choiceroom2a2 == "I" || choiceroom2a3 == "I"){
        gun = 1;
        player.update_weapon("gun");
    }
    //加天赋
    return room3(player);
}
Player room3(Player player){
    string storyroom3 = "“Help! Help! Is there someone who can save me? Help! Help!” you hear the grieved roar behind a door. “It’s definitely not produced by zombies.” whisper by you.";
    string optionroom3a = "What will you do next?  A.Open the door to save the victim  B. Do nothing and continue the game";
    cout << storyroom3 << endl;
    cout << optionroom3a << endl;
    string choiceroom3a;
    cin >> choiceroom3a;
    if(choiceroom3a == "A"){
        cout << "That was said by a group of zombies, they just pretend to be human." << endl;
        //减少生命值， 除非在room2选了枪
        if(gun == 1){
            return room4(player);
        }
        else{
             // player.update_HP(-0.1*(player.get_HP())); // lose 10% life
        }
    }
    else{
        return room4(player);
    }
    return player;
}
Player room4(Player player){
    string storyroom4 = "The terrifying sound pronounced by the zombies appear again from the corridor, there are 5 guns in the room and you can tell they are capable for war. What is more, there is huge probability that you can win more equips if you win.";
    string optionroom4a = "What is your choice?  A.Using the equips to fight against zombies  B. go forward to the next room.";
    cout << storyroom4 << endl;
    cout << optionroom4a << endl;
    string choiceroom4a;
    cin >> choiceroom4a;
    if(choiceroom4a == "A"){
         // player.update_HP(-0.1*(player.get_HP())); // lose 10% life
         gun = 0;
         return room5(player);
        //损失生命值和所有枪
    }
    else{
        return room5(player);
    }
}
Player room5(Player player){
    if(nightvision == 1){
        string strroom5a = "The wall of this room is made of thick cement, the door you pass through is so similar to those in military bases, so substantial, even an atomic bomb cannot break it. It is the first time you are able to relax a little bit after boarding the train. Suddenly, you found that your feet kick to something then you bend down to see what is that. The environment is too dark so you took long time to adapt to the darkness.";
        string strroom5b = "After a while, you see there is a a skeleton on the ground. “Aaaaaaaaaaaaaaaaaaa!” you shouted with great fear. At that moment, you decide to escape to outside nut the sound of hungry zombies stop you. Soon you realized a stationary skeleton is far less threatening than moving zombies. Then, you saw a piece of paper next to the skeleton and you start reading it.";
        string letterroom5 = "Dear boy/girl  This is my last letter in this world. Soon I will be crazy and may die soon. This letter may help you survive and go back home. I suppose you know the meaning of “666”, the next room is Room 6. I saw there is a huge painting of “666” on the wall of room 6. Be careful my friend, this will definitely bring bad luck to you. Trust me. Your loved ones are all waiting for you in your city. Good luck. Sincerely";
        string option5a = "What is your choice?  A.Trust the writer go to the other door (not the door you enter the room!) B. Don’t trust the writer.";
        cout << strroom5a << endl;
        cout << strroom5b << endl;
        cout << letterroom5 << endl;
        cout << option5a << endl;
        string choice5a;
        cin >> choice5a;
        if(choice5a == "A"){
            string strroom5b = "One wall begin to have a crack, then the crack becomes larger and larger. On the instant moment, the wall breaks. You feel terrified and aim at forward in order to kill the zombie coming from outside. ";
            string strroom5c = "However, there becomes silent after the fall of the wall. After making sure there is no threatening object inside your eyesight, you walk forward to enter the next room.";
            cout << strroom5b << endl;
            cout << strroom5c << endl;
            return room7(player);
        }
    }
    else{
            cout <<"The wall cracks then you enter the next room. You find the room is empty. "<< endl;
            return room6(player);
    } 
}
Player room6(Player player){
    string storyroom6a = "The letter’s writer is right, there is three “6” painted on the wall with bright red. Maybe too much paint was used so the excess paint flow downward in a winding route, just like the words are bleeding. You haven’t know the format of the room tell you all about tour future. Suddenly,";
    string storyroom6b = "you feel much lighter because you lose all your equips. “Hahahahahahahahahahahahahahaha” a voice come out with unbridled style. According to the voice, you found 4 cards on the table and you are forced to choose one card “If you refuse to choose a card, you will be surrounded by the zombies! Hahahahahahahaha” said the ownerless voice.";
    string option6a = "What is your choice?  A.Card A   B. Card B   C. Card C   D. card D";
    cout << storyroom6a << endl;
    cout << storyroom6b << endl;
    cout << option6a << endl;
    string choice6a;
    cin >> choice6a;
    if(protectivetalisman == 0){
        //玩家死了
        cout << "“Hahahahahahahahahahahahahahha” The voice becomes more aggressive, you feel the environment is so gruesome and frightening. Suddenly, there is ghost come out from every side, corner of the room. You lose consciousness gradually. " << endl;
        return player;
        // player.update_HP(-1*(player.get_HP())); // die
    }
    else{
        return room7(player);
    }
}
Player room7(Player player){
    cout << " You keep walking and looking for way to go out at the same time. In a twinkling, you saw a flash of reflected light, it is so dazzling that you close your eyes at once by instinct." << endl;
    cout << "You look around to find the light source, then you find there is a window on the wall. At the same time, you observe a secret door on the wall. " << endl;
    string option7a = "What is your choice?  A.Climb the window to go out B.Keep walking in the room C.Walk into the secret door D. start to run";
    cout << option7a << endl;
    string choice7a;
    cin >> option7a;
    if(choice7a == "A"){
       return room3(player);
    }
    else if(choice7a == "B"){
        return room11(player);
    }
    else{
        return room8(player);
    }
}
Player room8(Player player){
    cout << "Congratulation to you to be still alive in the game. This room is very large, you plan to walk around the 4 walls to find useful information or way to outside." << endl;
    cout << "On the way, you saw 2 people lie prone on the ground, devour on tumble of raw, putrefy meat like a wolf. “Why do they eat these? Where does the meat come from?” you whisper quietly." << endl;
    string option8a = "What is your choice?  A. Walk close to them to see who and how are they B. Walk to the other end of the room";
    cout << option8a << endl;
    string choice8a;
    cin >> choice8a;
    if(choice8a == "A"){
        if(gun == 1){
            //player is dead here
            cout << "The two 'people' realized you are close to them so they stand up and try to catch you. " << endl;
            cout << "You used the gun to kill the 2 zombies at once. However, the zombies have very strong hearing, more and more zombies are attracted by the sound of firing. Soon, you ran out of bullets and become unable to fight against the zombies. You are killed by the zombies at last. " << endl;
            // player.update_HP(-1*(player.get_HP())); // die
            return player;
        }
        else{
            cout << "“Aaaaaaaaa” you are scared by the zombies, you started escaping. Luckily, there is a door so you enter the next room. " << endl; 
            return room9(player);
        }
    }
    else{
        return room11(player);
    }
}
Player room9(Player player){
    cout << "Luckily, this room is safe without zombies. Now there are 2 ways in front of you." << endl;
    cout << "What is your choice?  A: the way in the left  B: the way in the right" << endl;
    string choiceroom9;
    cin >> choiceroom9;
    if(choiceroom9 == "A"){
        return room10(player);
    }
    else{
        return room11(player);
    }
}
Player room10(Player player){
    return room4(player);
}
Player room11(Player player){
    cout << "In this room, there are 3 treasure chest and you can take every thing from them. Then you will go forward" << endl;
    //The player will get 25 energy sugar, 3 medicine and 1 armour.
    return room13(player);
}
Player room13(Player player){
    cout << "This room’s ground is made of transparent glass. You can see the lower room is full of zombies, you cannot tell how many of them but you are sure you can’t survive even though use up your equips if enter there." << endl;
    cout << "Now there are 2 ways in front of you. What is your choice?  A: the way in the left  B: the way in the right" << endl;
    string choiceroom13;
    cin >> choiceroom13;
    return player;
}

int main(){
    Player player;
    room13(player);
}