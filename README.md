# Simple_pipeline_with_instruction_decoder
The main aim of the project is to develop the simulated pipeline with an instruction decoder.

**Pipeline follow three stages are as follows-**
<ol>
  <li> 1 stage for fetch (IF) </li>
  <li> 1 stage for decode (ID) </li>
  <li> 1 stage for execution (EX) </li>
</ol>

Additionally, the pipeline supports 4B fixed-length instructions, which stands 1B for opcode, 1B for destination and 2B for two operands. The destination and left operands are  always registers. The right operand can be either register or an immediate value.
