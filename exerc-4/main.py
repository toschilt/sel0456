#Lucas Toschi de Oliveira (11234190)
#Aplicativo que realiza o cálculo da seção transversal do fio.
#Precisa de tensão de entrada, comprimento, corrente e resistividade do material.

import gi
gi.require_version("Gtk", "3.0")

from gi.repository import Gtk

builder = Gtk.Builder()
builder.add_from_file("window.glade")

class Handler:
    def onDestroy(self, *args):
        Gtk.main_quit()

    def buttonClick(self, *args):
        resistividade = float(builder.get_object("resistividadeEntry").get_text())
        corrente = float(builder.get_object("correnteEntry").get_text())
        comprimento = float(builder.get_object("comprimentoEntry").get_text())
        tensaoEntrada = float(builder.get_object("tensãoEntradaEntry").get_text())

        #Cálculo utilizando a expressão da resistividade de um material.
        tensaoQueda = (2.5*tensaoEntrada)/100
        resistencia = tensaoQueda/corrente
        area = resistividade*0.00000001*comprimento/resistencia

        builder.get_object("secaoOut").set_text('{:0.3e}'.format(area))

builder.connect_signals(Handler())
window = builder.get_object("window1")
window.show_all()

Gtk.main()