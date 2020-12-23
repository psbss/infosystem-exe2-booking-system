# Booking_system
> ジョンソン法を利用した予約システム

## Get Started
```
git clone https://github.com/psbss/infosystem-exe2-booking-system
cd infosystem-exe2-booking-system
```

- Build
```
cd src/
make
```

- Clean .o file
```
make clean
```

- Clean .a / .o / exe file
```
make fclean
```

- Delete generated files / ReBuild
```
make re
```

## Language
- C言語  
メイン利用言語  
プログラム/アルゴリズムの作成に使用
  
- pu言語
UML作成に利用

## Directory tree
```
.
├── README.md
├── src
│   ├── Makefile
│   ├── dev.c
│   ├── inquiry.c
│   ├── johnson_algorithm.c
│   ├── lib.c
│   ├── main.c
│   └── mylib.h
└── uml
    ├── dist
    │   ├── activity
    │   │   └── activity.png
    │   ├── flowchart
    │   │   └── flowchart.png
    │   └── usecase
    │       └── usecase.png
    └── src
        ├── activity.pu
        ├── flowchart.pu
        └── usecase.pu
```
