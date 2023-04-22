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
            cout << train22 << endl;
            string choice2b;
            cin >> choice2b;
            if(choice2b == "A"){
                return train3(player);
                protectivetalisman = 1;
            }
            else{
                string train23 = "After a while, you hear the sound of dithering coins. A beggar is walking around the train.";
                string option2c = "What is your option?  A.Feel fear and walk away   B. Report to the station police there is a beggar  C. give him some money ";
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
    }else{
        return train3(player);
    }
}
Player train3(Player player){
    string storytrain3a = "Suddenly, you believe the feel in your mind: the train is weird because of the things happen and the people you meet on the train, it just like the horror movies you watched before. Then, you begin to suffer in extreme fear and worrying whether can go back home safely, lie in your bed tonight.";
    string storytrain3b = "However, the things happen minutes ago are not the last and are not the worst. Soon you saw the railway platform but the train does not seems to stop.";
    string option3a = "What is your option?   A: break the window and escape  B: Stay in the train  C:Discuss the situation with people nearby";
    cout << storytrain3a << endl;
    
    cout << storytrain3b << endl;
    cout << option3a << endl;
    if(protectivetalisman == 1){
        cout << "D: Go to the driver’s cab to ask the driver what’s going on" << endl; 
    }
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
    string option4a = "What option will you choose?   A.Get off the car with nothing  B. Get off the car with the a fire hammer  C. stay in the train";
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
        cout << "You are killed by the zombie driver - the driver of the train" << endl;
        return player;
        
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
    cout<<"this is readme"<<endl;
    // readme
    return player;
}
Player room2(Player player){
    string storyroom2a = "In this room, there is a treasure box, you can take 1 of the equips, use your chance wisely”";
    cout << storyroom2a << endl; //room 2 的宝箱不刷treasure box
    return player;
}
Player room3(Player player){
    string storyroom3 = "“Help! Help! Is there someone who can save me? Help! Help!” you hear the grieved roar behind a door. “It’s definitely not produced by zombies.” whisper by you.";
    string optionroom3a = "What will you do next? ";
    cout << storyroom3 << endl;
    cout << optionroom3a << endl;
    return player;
}//room 3 C提示前面似乎有什么东西 暗房的*必刷vision天赋
Player room4(Player player){
    string storyroom4 = "The terrifying sound pronounced by the zombies appear again from the corridor, there is a treasure box in the room and you can tell they are capable for war. What is more, there is huge probability that you can win more equips if you win.";
    cout << storyroom4 << endl;
    return player;
}
Player room5_Hidden(Player player){
        string strroom5a = "The wall of this room is made of thick cement, the door you pass through is so similar to those in military bases, so substantial, even an atomic bomb cannot break it. It is the first time you are able to relax a little bit after boarding the train. Suddenly, you found that your feet kick to something then you bend down to see what is that. The environment is too dark so you took long time to adapt to the darkness.";
        string strroom5b = "After a while, you see there is a a skeleton on the ground. “Aaaaaaaaaaaaaaaaaaa!” you shouted with great fear. At that moment, you decide to escape to outside nut the sound of hungry zombies stop you. Soon you realized a stationary skeleton is far less threatening than moving zombies. Then, you saw a piece of paper next to the skeleton and you start reading it.";
        cout << strroom5a << endl;
        cout << strroom5b << endl;
        return player;
}
Player room5_Letter(Player player){
    string letterroom5 = "Dear boy/girl  This is my last letter in this world. Soon I will be crazy and may die soon. This letter may help you survive and go back home. I suppose you know the meaning of “666”, the next room is Room 6. I saw there is a huge painting of “666” on the wall of room 6. Be careful my friend, this will definitely bring bad luck to you. Trust me. Your loved ones are all waiting for you in your city. Good luck. Sincerely";
    cout << letterroom5 << endl;
    return player;
}
Player room5 (Player player){
    cout <<"The wall cracks then you enter the next room. You find the room is empty. "<< endl;
    return player;
}
Player room6(Player player){
    string storyroom6a = "The letter’s writer is right, there is three “6” painted on the wall with bright red. Maybe too much paint was used so the excess paint flow downward in a winding route, just like the words are bleeding. You haven’t know the format of the room tell you all about tour future. Suddenly,";
    string storyroom6b = "“Hahahahahahahahahahahahahahaha” a voice come out with unbridled style. You are surrounded by the zombies! Hahahahahahahaha” said the ownerless voice.";
    cout << storyroom6a << endl;
    cout << storyroom6b << endl;

    cout << "Luckily you find a secret door in the zombie horde that seems to lead somewhere. You entered."<<endl;
    player.set_loc({8,43});
    return player;
}
Player room7(Player player){
    cout << " You keep walking and looking for way to go out at the same time. In a twinkling, you saw a flash of reflected light, it is so dazzling that you close your eyes at once by instinct." << endl;
    cout << "You look around to find the light source, then you find there is a window on the wall. At the same time, you observe a secret door on the wall. " << endl;
    return player;
}
Player room7_secretdoor(Player player){ //room 7 #
    cout << "You opened the secret door and walked in, you don't know where the road leads. You don't know how long after walking and you find yourself walking back to a familiar place."<<endl;
    player.set_loc({2,10});
    return player;
}
Player room7_window(Player player,Monster monster){// room 7 W
    cout << "As soon as you get to the window, a zombie rushes towards you..."<<endl;
    player = attack(player, monster);//powerful monster
    return player;
}

Player room8(Player player){
    cout << "Congratulation to you to be still alive in the game. This room is very large, you plan to walk around the 4 walls to find useful information or way to outside." << endl;
    cout << "On the way, you saw 2 people lie prone on the ground, devour on tumble of raw, putrefy meat like a wolf. “Why do they eat these? Where does the meat come from?” you whisper quietly." << endl;
    cout << "The two 'people' realized you are close to them so they stand up and try to catch you. " << endl;
    return player;
}
Player room9(Player player){
    cout << "Luckily, this room is safe without zombies. Now there are 2 ways in front of you." << endl;
    cout << "What is your choice?  The way in the left OR The way in the right ? " << endl;
    return player;
}
Player room10_secretdoor(Player player){//room 10 #
    player.set_loc({6,31});
    return player;
}
Player room11(Player player){
    cout << "In this room, there are 3 treasure box and you can take every thing from them. Then you will go forward" << endl;
    cout << "2 of the boxes are hidden"
    //The player will get 25 energy sugar, 3 medicine and 1 armour.
    return room13(player);
}
Player room13(Player player){
    cout << "This huge room’s ground is made of transparent glass. You can see the lower room is full of zombies, you cannot tell how many of them but you are sure you can’t survive even though use up your equips if enter there." << endl;
    cout << "But at the same time, you also see a light at the end of the room, it seems to be coming from outside, but unfortunately, a behemoth guards it, it seems to be more powerful than the zombies you accidentally encounter"<<endl;
    return player;
}
