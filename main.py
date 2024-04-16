from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.screenmanager import Screen , ScreenManager
from threading import Thread
from kivy.clock import Clock
from kivy.app import App
from kivy.lang import Builder
#from kivy.uix.gridlayout import GridLayout
#from kivy.animation import Animation
from kivy.uix.image import Image
#from kivy.uix.label import Label
from kivy.uix.scatter import Scatter
#from kivy.uix.progressbar import ProgressBar
#from kivy.properties import NumericProperty
#from kivy.properties import BoundedNumericProperty
from kivy.properties import StringProperty, NumericProperty, BoundedNumericProperty
from kivy.core.window import Window
from kivy.animation import Animation
#from math import sin
from kivy.uix.stencilview import StencilView
from kivy_garden.graph import Graph, MeshLinePlot, LinePlot, SmoothLinePlot
from kivy.factory import Factory


import configparser


config = configparser.ConfigParser()
config.read('config.ini')
Window.size = (int(config['screen']['x']), int(config['screen']['y']))


class Dashboard(FloatLayout):
    def __init__(self, **kwargs):
        super(Dashboard, self).__init__(**kwargs)
        self.background_image = Image(source='images/bg.png', size=self.size)
        self.clock = Label(text='[color=ffffff]HELLO[/color]', markup = True, font_size=100, pos=(1, 1) , font_name='fonts/hemi_head_bd_it.ttf')
        
        self.add_widget(self.background_image)
        self.add_widget(self.clock)

        Clock.schedule_interval(lambda dt: self.update_loop(), 1)
    
    def update_loop(self):
        print("loop")
        



class BoxApp(App):
    def build(self):
        dashboard = Dashboard()
        return dashboard


if __name__ == '__main__':
    BoxApp().run()













