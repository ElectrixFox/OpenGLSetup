from tkinter import *
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

top = Tk()

top.geometry("200x100")

b = Button(top, text = "Build", command=Runmake)
r = Button(top, text = "Run", command=RunApp)
both = Button(top, text = "Both", command=OnPress)

b.pack()
r.pack()
both.pack()

top.mainloop()