#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd -- "$script_dir/.." && pwd)"
source_dir="$repo_root/skill/ros2-learning-coach"
codex_home="${CODEX_HOME:-${HOME:?HOME is required}/.codex}"
target_dir="$codex_home/skills/ros2-learning-coach"

if [[ ! -f "$source_dir/SKILL.md" || ! -f "$source_dir/agents/openai.yaml" ]]; then
  printf 'Skill source is incomplete: %s\n' "$source_dir" >&2
  exit 1
fi

mkdir -p "$target_dir/agents"
cp "$source_dir/SKILL.md" "$target_dir/SKILL.md"
cp "$source_dir/agents/openai.yaml" "$target_dir/agents/openai.yaml"

printf 'Installed ros2-learning-coach to %s\n' "$target_dir"
printf 'Re-run this script after pulling skill updates.\n'
