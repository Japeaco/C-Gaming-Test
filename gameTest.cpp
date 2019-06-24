// gameTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

array<string, 5> items{};
string mystr;

bool searchInv(string item) {
	for (int n = 0; n < items.size(); n++) {
		if(items[n] == item){
			return true;
			break;
		}
	}
	return false;
}

bool addInv(string item) {
	for (int n = 0; n < items.size(); n++) {
		if (items[n] == item) {
			return false;
			break;
		}
		else if (items[n] == "") {
			items[n] = item;
			break;
		}
	}
	return true;
}

void examineInv() {
	cout << "You take a look at your inventory." << endl;
	for (int n = 0; n < items.size(); n++) {
		if (items[0] == "") {
			cout << "inventory is empty." << endl;
			break;
		}
		else {
			cout << items[n] << endl;
		}
	}
}

int main()
{
    cout << "Welcome! You can go north, east, south, or west. type 'look' to look around, or type 'examine' to look at items in inventory." << endl;
middle:
	cout << "You are in the middle of a room." << endl;
middleretry:
	getline(cin, mystr);
	if (mystr == "north" || mystr == "walk north") {
		cout << "You walk North." << endl;
		goto door;
	}
	else if (mystr == "east" || mystr == "walk east") {
		cout << "You walk East." << endl;
		goto drawers;
	}
	else if (mystr == "south" || mystr == "walk south") {
		cout << "You walk South." << endl;
		goto bed;
	}
	else if (mystr == "west" || mystr == "walk west") {
		cout << "You walk West." << endl;
		goto window;
	}
	else if (mystr == "look" || mystr == "look around") {
		cout << "You appear to be in a bedroom of sorts. There is a door to your North, drawers to your East, " << endl;
		cout << "a bed behind you, to the South, and a window to the West." << endl;
		goto middleretry;
	}
	else if (mystr == "examine") {
		examineInv();
		goto middleretry;
	}
	else {
		cout << "You cannot do that." << endl;
		goto middleretry;
	}
door:
	cout << "You are in front of a large, oak door. There are no discernable features aside from " << endl;
	cout << "an intimidating steel padlock." << endl;
doorretry:
	getline(cin, mystr);
	if (mystr == "north" || mystr == "walk north") {
		cout << "You walk into the door and bump your head." << endl;
		cout << "\"ow\"" << endl;
		goto doorretry;
	}
	else if (mystr == "east" || mystr == "walk east") {
		cout << "You walk East." << endl;
		goto drawers;
	}
	else if (mystr == "south" || mystr == "walk south") {
		cout << "You walk South." << endl;
		goto middle;
	}
	else if (mystr == "west" || mystr == "walk west") {
		cout << "You walk West." << endl;
		goto window;
	}
	else if (mystr == "open" || mystr == "open door") {
		cout << "The door is locked, dummy." << endl;
		goto doorretry;
	}
	else if (mystr == "look at lock" || mystr == "examine lock") {
		cout << "big ol' unbreakable lock." << endl;
		goto doorretry;
	}
	else if (mystr == "use key") {
		cout << "Specify which key." << endl;
		goto doorretry;
	}
	else if (mystr == "use large key") {
		if (searchInv("large key")) {
			cout << "You slam the massive key into the lock. You turn it left, then right, then left some more." << endl;
			cout << "You hear an audible click, and the lock splits open." << endl;
			cout << "\"freedom at last\"" << endl;
			goto freedom;
		}
		else {
			cout << "You do not have this item." << endl;
			goto doorretry;
		}
	}
	else if (mystr == "use small key") {
		if (searchInv("small key")) {
			cout << "You attempt to use the tiny key on the rather large lock." << endl;
			cout << "You frantically jiggle the key, but it does not open the lock." << endl;
			cout << "defeated, you return the key to your pocket." << endl;
			goto doorretry;
		}
		else {
			cout << "You do not have this item." << endl;
			goto doorretry;
		}
	}
	else if (mystr == "look" || mystr == "look around") {
		cout << "It's a door; It's not going anywhere, and you certainly arent either." << endl;
		goto doorretry;
	}
	else if (mystr == "examine") {
		examineInv();
		goto doorretry;
	}
	else {
		cout << "You cannot do that." << endl;
		goto doorretry;
	}
drawers:
	cout << "You find a set of lightly colored wooden drawers. There are three drawers here; top, middle and bottom." << endl;
drawersretry:
	getline(cin, mystr);
	if (mystr == "north" || mystr == "walk north") {
		cout << "You walk North." << endl;
		goto door;
	}
	else if (mystr == "east" || mystr == "walk east") {
		cout << "You walk East and stub your toe on the drawers." << endl;
		cout << "\"ow\"" << endl;
		goto drawersretry;
	}
	else if (mystr == "south" || mystr == "walk south") {
		cout << "You walk South." << endl;
		goto bed;
	}
	else if (mystr == "west" || mystr == "walk west") {
		cout << "You walk West." << endl;
		goto middle;
	}
	else if (mystr == "open middle" || mystr == "open middle drawer") {
		cout << "You open the middle drawer. You find nought but lady garments; you'd love to try them on but this isn't the time." << endl;
		cout << "You close the drawer." << endl;
		goto drawersretry;
	}
	else if (mystr == "open bottom" || mystr == "open bottom drawer") {
		if ((searchInv("small key"))) {
			cout << "You open the bottom drawer again, but to your dismay there is not anything else of interest." << endl;
			cout << "You close the drawer." << endl;
			goto drawersretry;
		}
		else{
			cout << "You open the bottom drawer and notice a dull looking key. Will you pick it up?" << endl;
		openbottom:
			getline(cin, mystr);
			if (mystr == "get key" || mystr == "pick up key" || mystr == "yes") {
				cout << "You plunge your hand in, fearing if it could suddenly bite your hand off. " << endl;
				cout << "Your cat like reflexes allow you to grab the key with lightning fast speeds. " << endl;
				cout << "Wiping the sweat from your brow, you pocket the tiny key and close the drawer." << endl;
				addInv("small key");
				goto drawersretry;
			}
			else if (mystr == "no" || mystr == "close" || mystr == "close drawer") {
				cout << "Too risky. You do not pick up the key; you wave goodbye and close the drawer." << endl;
				goto drawersretry;
			}
			else {
				cout << "You cannot do that." << endl;
				goto openbottom;
			}
		}
	}
	else if (mystr == "open top" || mystr == "open top drawer") {
		cout << "You open the top drawer, but find only invaluable trinkets." << endl;
		cout << "You close the drawer." << endl;
		goto drawersretry;
	}
	else if (mystr == "look" || mystr == "look around") {
		cout << "The drawers seem friendly enough. You could try opening them, if they don't bite." << endl;
		goto drawersretry;
	}
	else if (mystr == "examine") {
		examineInv();
		goto drawersretry;
	}
	else {
		cout << "You cannot do that." << endl;
		goto drawersretry;
	}
bed:
	cout << "You are in front of a Queen size bed; it is neatly made with bright red sheets and dangling gold tassles." << endl;
	cout << "It has two fluffy red pillows to match." << endl;
bedretry:
	getline(cin, mystr);
	if (mystr == "north" || mystr == "walk north") {
		cout << "You walk North." << endl;
		goto middle;
	}
	else if (mystr == "east" || mystr == "walk east") {
		cout << "You walk East." << endl;
		goto drawers;
	}
	else if (mystr == "south" || mystr == "walk south") {
		cout << "You walk South and fall face first onto the bed. It is perhaps the softest bed in the land." << endl;
		cout << "Fighting the urge to sleep, you roll off onto the floor." << endl;
		cout << "\"ow\"" << endl;
		goto bed;
	}
	else if (mystr == "west" || mystr == "walk west") {
		cout << "You walk West." << endl;
		goto window;
	}
	else if (mystr == "lift right pillow" || mystr == "look under right pillow") {
		cout << "peering delicately under the right pillow you find absolutely nothing, not even a tooth." << endl;
		goto bedretry;
	}
	else if (mystr == "lift left pillow" || mystr == "look under left pillow") {
		if (!(searchInv("large key"))) {
			cout << "lifting the left pillow, you find a rather large key hiding underneath. Will you take it?" << endl;
		liftleft:
			getline(cin, mystr);
			if (mystr == "get key" || mystr == "pick up key" || mystr == "yes") {
				cout << "You pick up the unusually large key and place it in your pocket." << endl;
				cout << "You then place the pillow back on top." << endl;
				addInv("large key");
				goto bedretry;
			}
			else if (mystr == "no" || mystr == "close" || mystr == "close drawer") {
				cout << "It looks far to peaceful to disturb. You kiss the key goodnight and place the pillow back on top." << endl;
				goto bedretry;
			}
			else {
				cout << "You cannot do that." << endl;
				goto liftleft;
			}
		}
		else {
			cout << "You delicately lift the pillow again for some reason. Nothing of use was found." << endl;
			cout << "You return the pillow to its previous position, neater than before." << endl;
			goto bedretry;
		}
	}
	else if (mystr == "look under" || mystr == "look under bed") {
		cout << "You dive to the floor and peer under the bed. It is completely bereft of monsters or anything of use." << endl;
		cout << "The dust causes you to sneeze, so you quickly get to your feet." << endl;
		goto bedretry;
	}
	else if (mystr == "look" || mystr == "look around") {
		if (!(searchInv("large key"))) {
			cout << "The bed is truly a wonder to behold, but through all its neatness you cant help but notice " << endl;
			cout << "the left pillow is slightly askew." << endl;
			goto bedretry;
		}
		else {
			cout << "The bed is truly a wonder, especially now the pillows are matching." << endl;
			goto bedretry;
		}
	}
	else if (mystr == "examine") {
		cout << "You take a look at your inventory." << endl;
		examineInv();
		goto bedretry;
	}
	else {
		cout << "You cannot do that." << endl;
		goto bedretry;
	}
window:
	cout << "You are in the middle of a room." << endl;
windowretry:
	getline(cin, mystr);
	if (mystr == "north" || mystr == "walk north") {
		cout << "You walk North." << endl;
		goto door;
	}
	else if (mystr == "east" || mystr == "walk east") {
		cout << "You walk East." << endl;
		goto middle;
	}
	else if (mystr == "south" || mystr == "walk south") {
		cout << "You walk South." << endl;
		goto bed;
	}
	else if (mystr == "west" || mystr == "walk west") {
		cout << "You walk West towards the window. Your crippling fear of heights kicks in." << endl;
		cout << "You collapse to the floor and assume the fetal position." << endl;
		cout << "Hours pass, you regain your composure and get to your feet, running from the window." << endl;
		goto windowretry;
	}
	else if (mystr == "look" || mystr == "look around") {
		cout << "The window is of average size; enough for a man to exit through were it not for the steel bars." << endl;
		cout << "Taking a closer look, you realise you are quite the way up." << endl;
		goto windowretry;
	}
	else if (mystr == "examine") {
		cout << "You take a look at your inventory." << endl;
		examineInv();
		goto windowretry;
	}
	else {
		cout << "You cannot do that." << endl;
		goto windowretry;
	}

freedom:
	cout << "The door swings open, and you waste no time rushing through." << endl;
	cout << "What wonders await?" << endl;
	cout << "Press enter" << endl;
	char ch;
	cin.get(ch);
	while (ch != '\n') {
		cin.get(ch);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
