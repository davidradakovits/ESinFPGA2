----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/08/2018 11:19:42 AM
-- Design Name: 
-- Module Name: PWM - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PWM is
    Port ( CLK : in STD_LOGIC;
           Duty_cycle : in unsigned (7 downto 0);
           LEDs : out STD_LOGIC_VECTOR(7 downto 0));
end PWM;

architecture Behavioral of PWM is

signal counter : unsigned (7 downto 0) :=(others=>'0');
signal max : unsigned (7 downto 0) := (others=>'1');

begin

process(clk)
begin
    if(clk'event and clk='1')then
        if(counter=0 and Duty_cycle >0) then
            LEDs<=(others=>'1');
        elsif(counter=Duty_cycle)then
            LEDs<=(others=>'0');
        elsif(counter=max) then
            counter<=to_unsigned(0,8);
        end if;    
    counter<=counter+1;
    end if;
end process;

end Behavioral;
