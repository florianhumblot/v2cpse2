# v2cpse2

To run each week, cd into the right directory and use either this command:

```
make clean build run
``` 

if you're using a headless linux shell, it will try to connect to a display, don't forget to export your display variable:
```
export DISPLAY=:0
```

if you're running either linux or windows, and SFML and gcc are correctly installed, you can run:

```
make clean build run-no-xdisplay
```

