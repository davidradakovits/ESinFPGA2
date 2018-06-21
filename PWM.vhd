library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity PWM is
    Port ( CLK : in STD_LOGIC;
           DUTY : in STD_LOGIC_VECTOR (7 downto 0);
           PWM_OUT : out STD_LOGIC_VECTOR (7 downto 0));
end PWM;

architecture Behavioral of PWM is
    signal TIMING : unsigned(7 downto 0) := (others => '0');
begin

    process(CLK)
    if(CLK'event and CLK='1') then
        if(TIMING = 0) then
            PWM_OUT <= (others => '1');
        end if;
        elsif(to_unsigned(DUTY) = TIMING) then
            PWM_OUT <= (others => '0');
        end if;
        if(TIMING = (others => '1')) then
            TIMING <= 0;
        end if;
    end if;

end Behavioral;
