#include "room.h"

int attractevilspirit = 0; 
int hammer = 0;
int nightvision = 0;
int protectivetalisman = 0;
int gun = 0;


Player train1(Player player){
    //story
    string storytrain1a = "Now it is 22:15 in a snowy and shivering night, you stand on a railway platform, waiting for the last train of the day to go home after a big day. Your home is 100 miles away from where you work. Suddenly, a gust of wind comes and you hear the sound of the train. At the same time, the station broadcasting says the train will arrive after 15 minutes. “It is quite strange” you whisper quietly.";

    // choice
    string storytrain1b = "What is your choice?\nA. Get in\nB. Wait for the next train";

    // define
    string choice;
    vector<string> fixed_ans;
    fixed_ans.push_back("a");
    fixed_ans.push_back("b");

    // Start choosing
    while (true){
        clear_screen();
        cout << storytrain1a << endl;
        cout << endl;
        cout << storytrain1b << endl;
        cout << endl;

        choice = slot_choice(fixed_ans);

        // check validation of user input
        if (choice == "false"){
            continue;
        }
        else{
            if(choice == "b"){
                clear_screen();
                
                cout << "You (shouting) : “What’s going on?”." << endl;
                cout << endl;
                cout << "An invisible, strange force push you into the train harshly." << endl;
                cout << endl;
            }
            else{
                cout << endl;
            }

            // Entering next slot
            short_pause();
            return train2(player);
        }
        
        return player;
    }
}


Player train2(Player player){
    //story
    string storytrain2a = "The door close as soon as you enter the train.";
    string storytrain2b = "After a while, an old granny appear in your eyesight. You saw she is close to you, walk in a very difficult way.";

    // choice
    string choicetrain2c = "What is your choice\nA. Give your seat to her\nB. Pretend as you haven’t see her";

    // define
    string choice;
    vector<string> fixed_ans;
    fixed_ans.push_back("a");
    fixed_ans.push_back("b");

    //start
    while (true){
        clear_screen();
        cout << storytrain2a << endl;
        cout << storytrain2b << endl;
        cout << endl;
        cout << choicetrain2c << endl;
        cout << endl;

        choice = slot_choice(fixed_ans);


        if (choice == "false"){
            continue;
        }
        else{
            // choose a
            if(choice == "a"){
                // story
                string grannysaid1 = "“Dear, do you believe in fortune? Do you believe there are too many things scientists are unable to prove?” said the granny.";

                // make a choice for the second time
                string grannysaid2 = "What is your choice?\nA. Answer “Yes”\nB. Answer “NO”\nC. Begin fear to the granny and go away";

                // define
                string choice2a;
                vector<string> fixed_ans_2;
                fixed_ans_2.push_back("a");
                fixed_ans_2.push_back("b");
                fixed_ans_2.push_back("c");
                
                // start
                while (true){
                    clear_screen();
                    cout << grannysaid1 << endl;
                    cout << endl;
                    cout << grannysaid2 << endl;
                    cout << endl;
                    
                    choice2a = slot_choice(fixed_ans_2);

                    if (choice2a == "false"){
                        continue;
                    }
                    else{
                        if(choice2a == "a" || choice2a == "b"){
                            // story
                            string grannysaid3 = "“Trust me then you will definitely be fine. Remember, take every chance you have” said the granny. Then she take 2 protective talisman and tell you “This is for you.”";

                            // make a choice for the third time
                            string train22 = "What is your choice?\nA: take the 2 protective talisman\nB: refuse and go away";

                            // define
                            string choice2b;
                            vector<string> fixed_ans_3;
                            fixed_ans_3.push_back("a");
                            fixed_ans_3.push_back("b");

                            // start
                            while (true){
                                clear_screen();
                                cout << grannysaid3 << endl;
                                cout << endl;
                                cout << train22 << endl;
                                cout << endl;

                                choice2b = slot_choice(fixed_ans_3);

                                if (choice2b == "false"){
                                    continue;
                                }
                                else{
                                    // choose a
                                    if(choice2b == "a"){
                                        // player will get a protectivetalisman
                                        player.talent.life += 1;
                                    }
                                    // choose b
                                    else{
                                        // story
                                        string train23 = "After a while, you hear the sound of dithering coins. A beggar is walking around the train.";

                                        // make a choice for the forth time
                                        string option2c = "What is your option?\nA. Feel fear and walk away\nB. Report to the station police there is a beggar\nC. give him some money";
                                        
                                        // define
                                        string choice2c;
                                        vector<string> fixed_ans_4;
                                        fixed_ans_4.push_back("a");
                                        fixed_ans_4.push_back("b");
                                        fixed_ans_4.push_back("c");

                                        // start
                                        while (true){
                                            clear_screen();
                                            cout << train23 << endl;
                                            cout << endl;
                                            cout << option2c << endl;
                                            cout << endl;

                                            choice2c = slot_choice(fixed_ans_4);
                                            if (choice2c == "false"){
                                                continue;
                                            }
                                            else{
                                                if(choice2c == "a" || choice2c == "b"){
                                                    // player will get a protectivetalisman
                                                    player.talent.life += 1;
                                                    clear_screen();
                                                    cout << "'Thank you very much and you are so kind!' said the beggar. Then he give you a piece of paper in return, you keep the paper and put it in the pocket" << endl;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    // enter next slot
                                    short_pause();
                                    return train3(player);
                                }
                            }
                        }
                        else{
                            // choose c
                            short_pause();
                            return train3(player);
                        }
                    }
                }
            }
            // choose b
            else{
                short_pause();
                return train3(player);
            }
        }
    }
}


Player train3(Player player){
    // story
    string storytrain3a = "Suddenly, you believe the feel in your mind: the train is weird because of the things happen and the people you meet on the train, it just like the horror movies you watched before. Then, you begin to suffer in extreme fear and worrying whether can go back home safely, lie in your bed tonight.";
    string storytrain3b = "However, the things happen minutes ago are not the last and are not the worst. Soon you saw the railway platform but the train does not seems to stop.";

    // choice
    string option3a = "What is your option?\nA: break the window and escape\nB: Stay in the train\nC:Discuss the situation with people nearby";
    
    //define
    string choice3a;
    bool hidden_choice = false;
    vector<string> fixed_ans;
    fixed_ans.push_back("a");
    fixed_ans.push_back("b");
    fixed_ans.push_back("c");

    // start
    while (true){
        clear_screen();
        cout << storytrain3a << endl;
        cout << storytrain3b << endl;
        cout << endl;
        cout << option3a << endl;

        // hidden choice
        if (player.talent.life != 0){
            cout << "D: Go to the driver’s cab to ask the driver what’s going on" << endl;
            if (hidden_choice == false){
                fixed_ans.push_back("d");
                hidden_choice = true;
            }
        }
        cout << endl;

        choice3a = slot_choice(fixed_ans);

        if (choice3a == "false"){
            continue;
        }
        else{
            cout << endl;
            if(choice3a == "a"){
                cout << "However, the train travels too fast, you got seriously injured after escape" << endl;
                // player will halve the life
                player.set_HP(player.get_HP()/2);
            }
            else if(choice3a == "c"){
                cout << "You begin talking with other passengers and know more about the strange things happen tonight. A few minutes later, one of the passengers give you necklace and according to him, the necklace can bring luck to its hosts. You take it and use it as a weapon against fear.'" << endl;
                // attractevilspirit = 1;
            }
            else if (choice3a == "d"){
                cout << "'Don't go!', the passenger shout at you. Then he tells you the reasons for those weird things happen: " << endl;
                cout << "From the other passengers, you know there is a strange virus spread accross the city. The people who are infected will lose awareness and become another creature --- zombie" << endl;
            }
            cout << endl;
            short_pause();
            return train4(player);
        }
    }
}


Player train4(Player player){
    // story
    string storytrain4a = "After a very long time, the train stop at a strange place, there is a disgusting smell in the air and there is dust everywhere, just like no one had been here for many years.";
    
    // choice
    // string option4a = "What option will you choose?\nA.Get off the car with nothing\nB. Get off the car with the a fire hammer\nC. stay in the train";
    string option4a = "What option will you choose?\nA.Get off the car with nothing\nB. Get off the car with the a fire hammer";

    // define
    string choice4a;
    vector<string> fixed_ans;
    fixed_ans.push_back("a");
    fixed_ans.push_back("b");
    // fixed_ans.push_back("c");

    while (true){
        clear_screen();
        cout << storytrain4a << endl;
        cout << endl;
        cout << option4a << endl;
        cout << endl;

        choice4a = slot_choice(fixed_ans);

        if (choice4a == "false"){
            continue;
        }
        else{
            /*
            if(choice4a == "a" || choice4a == "b"){
                short_pause();
                return train5(player);
            }
            */

            if(choice4a == "b"){
                // player get hammer
                player.update_weapon("hammer");
                // short_pause();
                // return train2(player);
            }
            /*
            else{
                // player die directly
                player.set_HP(0);
                cout << "You are killed by the zombie driver - the driver of the train" << endl;
                short_pause();
                return player;
            }
            */
            cout << endl;
            short_pause();
            return train5(player);
        }
    }
}


Player train5(Player player){
    clear_screen();
    // story 1
    string storytrain5a = "The luckiest thing is that you survive from the the crisis and do not need emergency medical treatment.";
    cout << storytrain5a << endl;
    short_pause();

    // story 2
    string storytrain5b = " However, you are the only survive of the incident, other passengers are all killed by the zombies, right now their bodies are scattered everywhere in the train.";
    cout << storytrain5b << endl;
    short_pause();

    // story 3
    string storytrain5c = "Now, you step out the train to the underground castle outside in order to seek chance to survive. Even though the situation makes you feel heart breaking, fear and downcast, you still want to leave this terrible place, go back to normal life.";
    cout << storytrain5c << endl;
    short_pause();
                
    // story 4
    string storytrain5d = "“I have to let everyone know here and protect others away from here!” whisper by you while walking forward to look for way to freedom. In the darkness,";
    cout << storytrain5d << endl;
    short_pause();
    
    // story 5
    string storytrain5e = "you hear some noise which you haven’t heard before but you are sure that this cannot be pronounced by human being, associated with news about zombies appear in the city, you recognized they are zombies. At the same time, you see a secret door on the wall on your left.";
    cout << storytrain5e << endl;

    // choice 5
    string option5a = "What is your choice?\nA: Use your body to smash the door\nB: Continue running forward";
    cout << option5a << endl;

    string choice5;
    vector<string> fixed_ans;
    fixed_ans.push_back("a");
    fixed_ans.push_back("b");

    // hidden choice
    if (player.get_weapon() == "hammer"){
        cout << "C: Use the fire hammer to smash the door " << endl;
        fixed_ans.push_back("c");
    }


    while (true){
        choice5 = slot_choice(fixed_ans);

        if (choice5 == "false"){
            continue;
        }
        else{
            if (choice5 == "a"){
                // player lose 10% HP
                player.set_HP(player.get_HP() * 9 / 10);
            }
            /*
            else if(choice5 == "b"){
                cout << "You are using all the energy left inside your body and ran as quickly as possible. In your memory, you had never ran so fast. Unfortunately, the zombies have no feelings so they are much faster than you, you hear the voice of zombies from far to near, from drained to exciting. You still cannot face the truth which you may not survive, you tried to ran faster and faster. Suddenly, you lose your balance, the zombies pounced on your, you lose your feeling and mind gradually in pain." << endl;
                player.set_HP(0);
                return player;
            }
            */
            return room1(player);
        }

    }
}


// room_parts
Player room1(Player player){
    // readme
    clear_screen();

    print_hint();

    short_pause();
    return player;
}

Player room2(Player player){
    // define
    string storyroom2a = "In this room, there is a treasure box, you can take 1 of the equips, use your chance wisely”";

    // operation
    clear_screen();
    cout << storyroom2a << endl; //room 2 的宝箱不刷treasure box
    cout << endl;

    short_pause();
    return player;
}

Player room3(Player player){
    // define
    string storyroom3 = "“Help! Help! Is there someone who can save me? Help! Help!” you hear the grieved roar behind a door. “It’s definitely not produced by zombies.” whisper by you.";
    string optionroom3a = "What will you do next? ";

    // operation
    clear_screen();
    cout << storyroom3 << endl;
    cout << optionroom3a << endl;
    cout << endl;

    short_pause();
    return player;
}//room 3 C提示前面似乎有什么东西 暗房的*必刷vision天赋

Player room4(Player player){
    // define
    string storyroom4 = "The terrifying sound pronounced by the zombies appear again from the corridor, there is a treasure box in the room and you can tell they are capable for war. What is more, there is huge probability that you can win more equips if you win.";
    
    // operation
    clear_screen();
    cout << storyroom4 << endl;
    cout << endl;

    short_pause();
    return player;
}

Player room5_Hidden(Player player){
    // define
    string strroom5a = "The wall of this room is made of thick cement, the door you pass through is so similar to those in military bases, so substantial, even an atomic bomb cannot break it. It is the first time you are able to relax a little bit after boarding the train. Suddenly, you found that your feet kick to something then you bend down to see what is that. The environment is too dark so you took long time to adapt to the darkness.";
    string strroom5b = "After a while, you see there is a a skeleton on the ground. “Aaaaaaaaaaaaaaaaaaa!” you shouted with great fear. At that moment, you decide to escape to outside nut the sound of hungry zombies stop you. Soon you realized a stationary skeleton is far less threatening than moving zombies. Then, you saw a piece of paper next to the skeleton and you start reading it.";
    
    // operation
    clear_screen();
    cout << strroom5a << endl;
    cout << strroom5b << endl;
    cout << endl;

    short_pause();
    return player;
}

Player room5_Letter(Player player){
    // define
    string letterroom5 = "Dear boy/girl  This is my last letter in this world. Soon I will be crazy and may die soon. This letter may help you survive and go back home. I suppose you know the meaning of “666”, the next room is Room 6. I saw there is a huge painting of “666” on the wall of room 6. Be careful my friend, this will definitely bring bad luck to you. Trust me. Your loved ones are all waiting for you in your city. Good luck. Sincerely";
    
    // operation
    clear_screen();
    cout << letterroom5 << endl;
    cout << endl;

    short_pause();
    return player;
}

Player room5 (Player player){
    clear_screen();
    cout <<"The wall cracks then you enter the next room. You find the room is empty. "<< endl;
    cout << endl;

    short_pause();
    return player;
}

Player room6(Player player){
    // define
    string storyroom6a = "The letter’s writer is right, there is three “6” painted on the wall with bright red. Maybe too much paint was used so the excess paint flow downward in a winding route, just like the words are bleeding. You haven’t know the format of the room tell you all about tour future. Suddenly,";
    string storyroom6b = "“Hahahahahahahahahahahahahahaha” a voice come out with unbridled style. You are surrounded by the zombies! Hahahahahahahaha” said the ownerless voice.";
    
    // operation
    clear_screen();
    cout << storyroom6a << endl;
    cout << storyroom6b << endl;

    cout << endl;
    short_pause();
    cout << endl;

    cout << "Luckily you find a secret door in the zombie horde that seems to lead somewhere. You entered."<<endl;
    player.set_loc({8,43});

    cout << endl;
    short_pause();
    return player;
}

Player room7(Player player){
    clear_screen();
    cout << " You keep walking and looking for way to go out at the same time. In a twinkling, you saw a flash of reflected light, it is so dazzling that you close your eyes at once by instinct." << endl;
    cout << "You look around to find the light source, then you find there is a window on the wall. At the same time, you observe a secret door on the wall. " << endl;
    
    cout << endl;
    short_pause();
    return player;
}
Player room7_secretdoor(Player player){ //room 7 #
    clear_screen();
    cout << "You opened the secret door and walked in, you don't know where the road leads. You don't know how long after walking and you find yourself walking back to a familiar place."<<endl;
    player.set_loc({2,10});

    cout << endl;
    short_pause();
    return player;
}
Player room7_window(Player player, Monster monster, Map map, int count){// room 7 W
    clear_screen();
    cout << "As soon as you get to the window, a zombie rushes towards you..."<<endl;
    player = attack(player, monster, map, count);//powerful monster

    cout << endl;
    short_pause();
    return player;
}

Player room8(Player player){
    clear_screen();
    cout << "Congratulation to you to be still alive in the game. This room is very large, you plan to walk around the 4 walls to find useful information or way to outside." << endl;
    cout << "On the way, you saw 2 people lie prone on the ground, devour on tumble of raw, putrefy meat like a wolf. “Why do they eat these? Where does the meat come from?” you whisper quietly." << endl;
    cout << "The two 'people' realized you are close to them so they stand up and try to catch you. " << endl;

    cout << endl;
    short_pause();
    return player;
}
Player room9(Player player){
    clear_screen();
    cout << "Luckily, this room is safe without zombies. Now there are 2 ways in front of you." << endl;
    cout << "What is your choice?  The way in the left OR The way in the right ? " << endl;
    
    cout << endl;
    short_pause();
    return player;
}

Player room10_secretdoor(Player player){//room 10 #
    clear_screen();
    player.set_loc({6,31});

    cout << "You have entered a secret door" << endl;

    cout << endl;
    short_pause();
    return player;
}
Player room11(Player player){
    clear_screen();
    cout << "In this room, there are 3 treasure box and you can take every thing from them. Then you will go forward" << endl;
    cout << "2 of the boxes are hidden";
    //The player will get 25 energy sugar, 3 medicine and 1 armour.
    cout << endl;
    short_pause();
    return room13(player);
}
Player room13(Player player){
    clear_screen();
    cout << "This huge room’s ground is made of transparent glass. You can see the lower room is full of zombies, you cannot tell how many of them but you are sure you can’t survive even though use up your equips if enter there." << endl;
    cout << "But at the same time, you also see a light at the end of the room, it seems to be coming from outside, but unfortunately, a behemoth guards it, it seems to be more powerful than the zombies you accidentally encounter"<<endl;
    
    cout << endl;
    short_pause();
    return player;
}
