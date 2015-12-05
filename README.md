# Monkey Translator
Simple tool to assist with translating of Monkey Island SE info files. MISE 2 game is not supported.

This tool was created for studying purposes. No guarantees are provided by the author. It allows to convert text strings from binary _info_ files of MISE game into separate text files (to allow translating) and to compose binary _info_ file with such modifications.

In this version there is no support for modifying _hint_ files. Lots of things are hardcoded and the code cannot be considered clean, but it suits its purpose just fine.

## Supported data files

- speech.info
- uiText.info

## Decompilation of info files

In this process all strings from original _info_ file are stored into text files separately for each language. Line breaks are detected and replaced with '\n'. At the output there are created text files containing strings for each stored language.

## Recreating info files from text files

The program expects the localized strings to be present in file _speech.sk_ or _uiText.sk_ based on parameters. Newly created files have extension _info.new_.
