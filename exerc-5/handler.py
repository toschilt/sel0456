from simon import Simon
from gi.repository import Gtk

class Handler:
    #Constructor.
    def __init__(self, windowBuilder):
        self.simon = Simon(windowBuilder)

    #Destroying and stopping program when press in close button.
    def onWindowDestroy(self, *args):
        Gtk.main_quit()

    #Starts the game.
    def onStartButtonPress(self, *args):
        self.simon.reset()

    #Gets the next sequence.
    def onProxButtonPress(self, *args):
        self.simon.next()

    #When the user presses the green button.
    def onGreenClicked(self, *args):
        self.simon.blink("green_button")

    #When the user presses the red button.
    def onRedClicked(self, *args):
        self.simon.blink("red_button")

    #When the user presses the yellow button.
    def onYellowClicked(self, *args):
        self.simon.blink("yellow_button")

    #When the user presses the blue button.
    def onBlueClicked(self, *args):
        self.simon.blink("blue_button")