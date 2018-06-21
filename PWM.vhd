library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity PWM is
    Port ( CLK : in STD_LOGIC;
           DUTY : in unsigned (7 downto 0);
           PWM_OUT : out STD_LOGIC_VECTOR (7 downto 0));
end PWM;

architecture Behavioral of PWM is
    signal TIMING : unsigned(7 downto 0) := (others => '0');
begin

    process(CLK)
    begin
    if(CLK'event and CLK='1') then
        if(TIMING = 0 and DUTY > 0) then
            PWM_OUT <= (others => '1');
        elsif(DUTY = TIMING) then
            PWM_OUT <= (others => '0');
        elsif(TIMING = 255) then
            TIMING <= to_unsigned(0,8);
        end if;
        TIMING <= TIMING+1;
    end if;
    end process;
end Behavioral;