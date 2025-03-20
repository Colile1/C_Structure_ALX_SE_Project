#!/bin/bash

# Update the package list
sudo apt update

# Install necessary packages for X Server compatibility (like x11-apps for testing)
sudo apt install -y x11-apps

# Set up DISPLAY environment variable
echo "Setting up DISPLAY environment variable..."
DISPLAY_IP=$(grep nameserver /etc/resolv.conf | awk '{print $2}')
echo "export DISPLAY=${DISPLAY_IP}:0.0" >> ~/.bashrc

# Reload .bashrc to apply changes
source ~/.bashrc

# Confirmation message
echo "X Server configuration completed successfully!"
echo "You can now test the setup by running: xclock or xeyes (if installed)"
