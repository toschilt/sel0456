#Class Simon.
#Implements the game itself.

import time
import random
from gi.repository import Gtk
from gi.repository import GLib

class Simon:
    #Constructor.
    def __init__(self, windowBuilder):
        self.windowBuilder = windowBuilder
        self.sequence = []

        self.colors = ["green_button", "red_button", "yellow_button", "blue_button"]
        random.seed()

    #Reset function. Called when the user press in start button.
    def reset(self):
        self.sequence = []

    #Call the old sequences.
    def newSequence(self):
        for color in self.sequence:
            self.blink(color)

        colorChosen = self.colors[random.sample(range(4), k = 1)[0]]
        self.blink(colorChosen)
        self.sequence.append(colorChosen)

    #Next sequence call.
    def next(self):
        GLib.timeout_add(1000, self.newSequence)

    #Turn on a button.
    def turnOn(self, buttonAlias):
        pngName = "light_" + buttonAlias + ".png"
        imageID = buttonAlias[:buttonAlias.find("_")] + "_image"
        imageObj = self.windowBuilder.get_object(imageID)
        imageObj.set_from_file(pngName)
        

    #Turn off a button.
    def turnOff(self, buttonAlias):
        pngName = buttonAlias + ".png"
        imageID = buttonAlias[:buttonAlias.find("_")] + "_image"
        imageObj = self.windowBuilder.get_object(imageID)
        imageObj.set_from_file(pngName)
    

    #Press one button.
    def blink(self, aliasButton):
        GLib.timeout_add(1000, self.turnOn, aliasButton)
        time.sleep(1)
        GLib.timeout_add(1000, self.turnOff, aliasButton)
        time.sleep(1)