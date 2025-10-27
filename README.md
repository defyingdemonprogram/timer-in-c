# Timer Quick Start

### Build & Run

**Using Makefile:**

```bash
make -B
./timer [time] [options]
```

**Without Makefile:**

```bash
mkdir -p build
gcc -Wall -Wextra -ggdb src/png2c.c -o build/png2c -lm
build/png2c assets/digits.png digits > src/digits.h
build/png2c assets/penger_walk_sheet.png penger > src/penger_walk_sheet.h
gcc -Wall -Wextra -ggdb src/main.c -o timer -lX11 -lXrandr -lGL -lm
```

> If no time is provided, the timer defaults to **stopwatch mode**. Time format: `1h2m3s` (hours, minutes, seconds). Options include starting paused or auto-exit on completion.


### Usage Examples

| Command           | Behavior                                |
| ----------------- | --------------------------------------- |
| `./timer`         | Stopwatch mode                          |
| `./timer 34`      | Countdown from 34 seconds               |
| `./timer 1h3m32s` | Countdown from 1h 3m 32s                |
| `./timer -e 43`   | Countdown from 43s, exits automatically |
| `./timer -p 43`   | Countdown from 43s, starts paused       |


### Controls

| Key              | Action                      |
| ---------------- | --------------------------- |
| <kbd>SPACE</kbd> | Pause/resume (Red = paused) |
| <kbd>+</kbd>     | Increase text size          |
| <kbd>-</kbd>     | Decrease text size          |
| <kbd>F11</kbd>   | Toggle full-screen          |

### Demo

![timer-demo](https://github.com/user-attachments/assets/b5a02a89-1a36-4e97-b6ca-59c2f6b1baee)

### References

* [RGFW GitHub](https://github.com/ColleagueRiley/RGFW)
* [libX11 GitHub](https://github.com/mirror/libX11)
* [libXrandr - X.org](https://www.x.org/wiki/libraries/libxrandr/)
* [stb GitHub](https://github.com/nothings/stb)
* [OpenGL Docs](https://docs.gl/)
