#Lucas Toschi de Oliveira (11234190)
#Aplicativo 

import gi
gi.require_version("Gtk", "3.0")

from gi.repository import Gtk
from handler import Handler

builder = Gtk.Builder()
builder.add_from_file("window.glade")

builder.connect_signals(Handler(builder))
window = builder.get_object("window")
window.show_all()

Gtk.main()