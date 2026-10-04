# 09. Note Template

Use this template when creating a new note for OS study.

## 1. Topic

- Title:
- Date:
- Related notes:

## 2. Concept summary

Explain the concept in plain words.

## 3. Core idea

Write the single most important idea in one sentence.

## 4. Why it matters

Why is this concept important in a real operating system?

## 5. Key definitions

- Definition 1:
- Definition 2:
- Definition 3:

## 6. Mechanism / how it works

Describe the mechanism step by step.

## 7. Example

Use a small example or pseudocode.

```c
// example here
```

or

```asm
; assembly example here
```

## 8. Common pitfalls

- Pitfall 1:
- Pitfall 2:
- Pitfall 3:

## 9. Important details

- detail 1
- detail 2
- detail 3

## 10. Related questions

- Q1:
- Q2:
- Q3:

## 11. Review questions

- Explain this concept in your own words.
- What problem does it solve?
- Why does it matter for OS design?
- Which lower-level concept does it depend on?

## 12. Quick summary

Write a 3-5 sentence summary.

## 13. Next step

What should be learned next?

## Example fill-in

### Topic
CPU registers

### Concept summary
Registers are fast storage inside the CPU used during instruction execution.

### Core idea
Registers hold the CPU's working state while instructions run.

### Why it matters
Without registers, the CPU would have no convenient place to keep currently processed data.

### Key definitions
- register
- instruction pointer
- stack pointer

### Mechanism
The CPU fetches instructions, loads operands into registers, executes logic, and stores results back to registers or memory.

### Example
```asm
mov rax, 10
mov rbx, 20
add rax, rbx
```

### Common pitfalls
- confusing registers with memory
- forgetting that registers are tiny and limited
- assuming a high-level language variable maps directly to one register

### Review questions
- What is the difference between a register and memory?
- Why do function calls use the stack?
- Why do CPUs need registers at all?
