wsl --install -d Ubuntu
sudo apt update && sudo apt upgrade -y
sudo apt install -y build-essential cmake git libsdl2-dev libeigen3-dev libglm-dev libglew-dev xorg-dev

#--------------------------------------------------------------------------------
sudo apt update && sudo apt upgrade -y
sudo apt install -y build-essential cmake git libsdl2-dev libgl1-mesa-dev libglew-dev libeigen3-dev libglm-dev xorg-dev

#--------------------------------------------------------------------------------
echo "export DISPLAY=$(grep nameserver /etc/resolv.conf | awk '{print $2}'):0.0" >> ~/.bashrc 
source ~/.bashrc
