from tkinter import *
from tkinter import ttk
from tkinter.ttk import *

import subprocess

def Runmake():
    print("Making")
    subprocess.run(["make"])

def RunApp():
    print("Running")
    subprocess.run(["./main"])

def OnPress():
    Runmake()
    RunApp()

box = 0 

def Commit(message, summary):
    cmdrl = "git commit -m "
    cmdrl += message
    cmdrl += " -m "
    cmdrl += summary
    print(cmdrl)
    print("Commiting")

top = Tk()
cB = Entry()
def OpenCommitBox():
    cB.pack()

top.title('Build tools')

style = ttk.Style()
style.theme_use('clam')

top.geometry("200x100")

b = Button(top, text = "Build", command=Runmake)
r = Button(top, text = "Run", command=RunApp)
both = Button(top, text = "Both", command=OnPress)

Cm = Button(top, text="Click to commit", command=OpenCommitBox)

b.pack()
r.pack()
both.pack()
Cm.pack()

top.mainloop()
