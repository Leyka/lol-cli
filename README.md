# lol-cli

Attempt to *replace* [WhatBuild](https://github.com/Leyka/WhatBuild) but not really.

Just a quick way to replace repetitive steps of opening browser and looking for League of Legends build.

## Usage

```sh
LoL-CLI.exe <champion> [OPTIONS]

OPTIONS:
-a, --aram       ARAM mode build [default]
-n, --normal     Normal mode build
-s, --site       Website to open with the build (u.gg, op.gg)
-h, --help       Halp!
```

`<champion>` can be an alias (ex. ww for Warwick) or a portion of the word (blitz for blitzcrank)

**Example**

```sh 
LoL-CLI.exe blitz --normal --site op.gg
```

## License

MIT 
