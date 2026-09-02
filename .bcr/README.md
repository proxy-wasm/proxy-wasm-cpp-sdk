# Bazel Central Registry (BCR) Publishing

This directory contains template files used to publish `proxy-wasm-cpp-sdk` to the [Bazel Central Registry](https://github.com/bazelbuild/bazel-central-registry).

## Overview

The BCR publishing automation uses these template files to create new entries in the Bazel Central Registry when a new release is tagged. This allows users to consume this SDK as a Bazel module using `bzlmod`.

## Files

### metadata.template.json

Contains metadata about the module including:
- Homepage and repository URL
- Maintainer information (populated from CODEOWNERS)
- Version tracking

**Note**: The maintainer information is populated from the CODEOWNERS file. The `versions` field is automatically updated by the publishing workflow.

### source.template.json

Defines how to fetch the source code for a release:
- Source archive URL pattern
- Archive integrity hash (filled automatically)
- Strip prefix for archive extraction

### presubmit.yml

Defines tests that run in BCR CI to validate each release:
- Test targets to build/run
- Bazel versions to test against
- Platforms to test on

## Publishing Process

When a new tag is pushed (e.g., `v1.0.0`):

1. The GitHub Actions workflow (`.github/workflows/publish-to-bcr.yml`) is automatically triggered
2. The workflow uses these template files to generate a BCR entry
3. A pull request is opened against https://github.com/bazelbuild/bazel-central-registry
4. Once approved by BCR maintainers, the PR is merged to publish the new version

## Maintainer Instructions

### Prerequisites

1. **Create a Personal Access Token (PAT)**:
   - Go to GitHub Settings > Developer settings > Personal access tokens > Tokens (classic)
   - Click "Generate new token (classic)"
   - Name it something like "BCR Publish Token"
   - Select scopes: `repo` (Full control of private repositories) and `workflow` (Update GitHub Action workflows)
   - Generate and copy the token

2. **Add the token as a repository secret**:
   - Go to your repository Settings > Secrets and variables > Actions
   - Click "New repository secret"
   - Name: `BCR_PUBLISH_TOKEN`
   - Value: Paste your PAT
   - Click "Add secret"

### Creating a Release

1. **Tag a new version**:
   ```bash
   git tag -a v1.0.0 -m "Release v1.0.0"
   git push origin v1.0.0
   ```

   This will automatically trigger the "Publish to BCR" workflow.

2. **Monitor the publish workflow**:
   - Go to Actions tab in your repository
   - Find the "Publish to BCR" workflow run
   - Ensure it completes successfully
   - Check https://github.com/bazelbuild/bazel-central-registry for the new pull request

3. **Complete the BCR submission**:
   - Review the pull request in the BCR
   - Wait for BCR maintainers to review and merge

### Troubleshooting

- **Workflow fails with authentication error**: Check that `BCR_PUBLISH_TOKEN` secret is set correctly
- **Workflow fails to create PR**: Ensure you have a fork of bazel-central-registry configured in the workflow
- **BCR CI fails**: Review the `presubmit.yml` configuration and ensure test targets are correct
- **Integrity hash mismatch**: Ensure the release archive is created correctly and hasn't been modified

## References

- [Bazel Central Registry](https://github.com/bazelbuild/bazel-central-registry)
- [publish-to-bcr documentation](https://github.com/bazel-contrib/publish-to-bcr)
- [Bzlmod User Guide](https://bazel.build/docs/bzlmod)
