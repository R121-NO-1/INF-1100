#!/bin/bash

URL="https://inf-0103.github.io/"

echo "🌐 Opening the INF-0103 website..."

# Detect the operating system and open the URL accordingly
if command -v xdg-open &> /dev/null; then
    xdg-open "$URL"
elif command -v open &> /dev/null; then
    open "$URL"
elif command -v start &> /dev/null; then
    start "$URL"
elif [[ -n "$IS_WSL" || "$(grep -i Microsoft /proc/version 2>/dev/null)" ]]; then
    cmd.exe /c start "$URL"
else
    echo "❌ Could not detect a browser command. Please visit: $URL"
    exit 1
fi

